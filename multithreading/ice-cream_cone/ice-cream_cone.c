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

void *manager(void *args){
    printf("Manager\n");
    return NULL;
}

void *customer(void *args){
    printf("Customer!\n");
    return NULL;
}

void *clerk(void *args){
    printf("Clerk!\n");
    return NULL;
}

void *cashier(void *args){
    printf("Cashier!\n");
    return NULL;
}

int main(int argc, char **argv){
    pthread_t thread[3];

    pthread_create(&thread[0], NULL, manager, NULL);
    pthread_create(&thread[1], NULL, cashier, NULL);
    pthread_create(&thread[2], NULL, customer, NULL);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    pthread_join(thread[2], NULL);

    return 0;
}