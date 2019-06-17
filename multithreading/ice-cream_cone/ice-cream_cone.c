/*
 * Problem statement:
 * - in an ice-cream shop there is a Manager and a Cashier
 * - 1-10 Customers visit the shop
 * - Each customer can order 1-4 cones and spwans 1 clerk/cone
 * - Each worker creates one cone and visits the manager's office
 *   to get the approval for the quality. If the quality is bad the
 *   clerk remakes the cone and returns back later.
 * - There cannot be more than 2 clerks in the Manager's office and
 *   can attend to only one clerk at a time.
 * - Once the customer gets his/her cone, he/she exits the shop after
 *   paying the cashier.
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>

#define TRUE  1
#define FALSE 0

#define MAX_CONES     4
#define MAX_CUSTOMERS 10
#define MAX_TIME      3

#define CREATE_CONE (sleep(rand()%MAX_TIME))

void *manager(void *args);
void *customer(void *args);
void *clerk(void *args);
void *cashier(void *args);

enum quality {
    PENDING = 0x00,
    GOOD    = 0x01,
    BAD     = 0x02
};

struct icecream_cone {
    enum quality approval_status;
    struct icecream_cone *next_request;
};

pthread_mutex_t cone_queue_lock;
struct icecream_cone *approval_queue = NULL;
struct icecream_cone *last_cone = NULL;

volatile uint32_t done = FALSE;

uint32_t submit_for_approval(struct icecream_cone *cone) {
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

void *manager(void *args){
    enum quality decision;

    while (done == FALSE) {
        if (approval_queue) {
            
            decision = PENDING;
            
            if (rand() % 2)
                decision = BAD;
            else
                decision = GOOD;


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

void *customer(void *args){
    uint32_t num_cones = rand() % MAX_CONES + 1;
    uint32_t index;
    pthread_t clerks[10];

    printf("Customer: %lu, Requested cones: %u\n", pthread_self(), num_cones);

    for(index = 0; index < num_cones; index++)
        pthread_create(&clerks[index], NULL, clerk, NULL);

    for(index=0; index < num_cones; index++)
        pthread_join(clerks[index], NULL);

    printf("Customer: %lu, Got all cones\n", pthread_self());

    return NULL;
}

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

void *cashier(void *args){
    return NULL;
}

int32_t main(int32_t argc, int8_t **argv){
    pthread_t thread[2 + MAX_CUSTOMERS];
    uint32_t num_customers;
    uint32_t index;

    if (pthread_mutex_init(&cone_queue_lock, NULL) != 0)
        return -1;

    srand(time(0));

    num_customers = rand() % MAX_CUSTOMERS + 1;

    pthread_create(&thread[0], NULL, manager, NULL);
    pthread_create(&thread[1], NULL, cashier, NULL);

    for (index = 2; index < 2 + num_customers; index++)
        pthread_create(&thread[index], NULL, customer, NULL);

    for (index = 2; index < 2 + num_customers; index++)
        pthread_join(thread[index], NULL);


    // This is the termination for the manager and cashier
    done = TRUE;

    for (index = 0; index < 2; index++)
        pthread_join(thread[index], NULL);

    return 0;
}
