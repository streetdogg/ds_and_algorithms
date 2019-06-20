#include "icecream.h"

static pthread_mutex_t cone_queue_lock;
static struct icecream_cone *approval_queue = NULL;
static struct icecream_cone *last_cone = NULL;

static uint32_t no_more_cones = FALSE;

static pthread_mutex_t cashier_queue_lock;
static uint32_t num_customers = 0;

/* 
 * Make payment to theCashier
 */
static void make_payment(){
    pthread_mutex_lock(&cashier_queue_lock);
    num_customers--;
    pthread_mutex_unlock(&cashier_queue_lock);
}

/*
 * Used to submit a cone created by the Clerk into
 * Manager's inspection queue.
 */
static uint32_t submit_for_approval(struct icecream_cone *cone) {
    pthread_mutex_lock(&cone_queue_lock);
    if (last_cone == NULL) {
        approval_queue = cone;
        last_cone = approval_queue;
    } else {
        last_cone->next_request = cone;
        last_cone = cone;
    }
    pthread_mutex_unlock(&cone_queue_lock);
}

/*
 * Initializes the Mutex variables and sets randomly the number
 * of customers in the store. Returns the number of customers.
 */
uint32_t open_store() {
    if (pthread_mutex_init(&cone_queue_lock, NULL) != 0)
        return -1;
    
    if (pthread_mutex_init(&cashier_queue_lock, NULL) != 0)
        return -2;

    srand(time(0));

    pthread_mutex_lock(&cashier_queue_lock);
    num_customers = rand() % MAX_CUSTOMERS + 1;
    pthread_mutex_unlock(&cashier_queue_lock);

    return num_customers;
}

/*
 * Fetches a Cone from the inspection queue and
 * decides if it's a GOOD or BAD cone. Exits when there
 * are no more cones to process.
 */
void *manager(void *args){
    enum quality decision;

    while (!no_more_cones) {
        if (approval_queue) {
            decision = (rand() % 2) ? BAD : GOOD;

            pthread_mutex_lock(&cone_queue_lock);
            approval_queue->approval_status = decision;
            if (approval_queue == last_cone) {
                approval_queue = NULL;
                last_cone = NULL;
            } else {
                approval_queue = approval_queue->next_request;
            }
            pthread_mutex_unlock(&cone_queue_lock);
        }
    }
    
    return NULL;
}

/*
 * Orders random quantities of Cone decided by MAX_CONES,
 * Spwans a Clerk for every cone needed and waits for 
 */
void *customer(void *args){
    uint32_t num_cones = rand() % MAX_CONES + 1;
    uint32_t index;
    pthread_t clerks[10];

    printf("CUSTOMER: %lu, Requested cones: %u\n", pthread_self(), num_cones);

    for(index = 0; index < num_cones; index++)
        pthread_create(&clerks[index], NULL, clerk, NULL);

    for(index=0; index < num_cones; index++)
        pthread_join(clerks[index], NULL);

    printf("CUSTOMER: %lu, Got all cones\n", pthread_self());

    make_payment();

    return NULL;
}

/*
 * Creates a Cone and waits for manager to approve the
 * quality. If manager is not happy, creates another cone.
 */
void *clerk(void *args){
    struct icecream_cone cone;

    do {
        cone.approval_status = PENDING;
        cone.next_request = NULL;
        
        CREATE_CONE;
        submit_for_approval(&cone);
        
        while (cone.approval_status == PENDING);
    } while (cone.approval_status == BAD);

    return NULL;
}

/*
 * Takes a while to process the payment,
 * reports the number of customer in queue,
 * signals the Manager to leave when all
 * Customers are served.
 */
void *cashier(void *args){
    while (num_customers){
        CASHIER_PROCESSING;
        printf("CASHIER: Customers in Queue: %u\n", num_customers);
    }

    no_more_cones = TRUE;
    
    return NULL;
}
