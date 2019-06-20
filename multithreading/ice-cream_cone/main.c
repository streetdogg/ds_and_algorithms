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

#include "icecream.h"

int32_t main(int32_t argc, int8_t **argv){
    pthread_t thread[2 + MAX_CUSTOMERS];
    uint32_t customer_count;
    uint32_t index;

    printf("\n-------------------- STORE OPEN --------------------\n\n");
    customer_count = open_store();

    pthread_create(&thread[0], NULL, manager, NULL);
    pthread_create(&thread[1], NULL, cashier, NULL);

    for (index = 2; index < 2 + customer_count; index++)
        pthread_create(&thread[index], NULL, customer, NULL);

    for (index = 0; index < 2 + customer_count; index++)
        pthread_join(thread[index], NULL);

    printf("\n-------------------- STORE CLOSE -------------------\n\n");
    return 0;
}
