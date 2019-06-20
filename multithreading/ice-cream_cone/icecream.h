#ifndef __ICECREAM_H_
#define __ICECREAM_H_

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
#define CASHIER_PROCESSING (sleep(rand()%MAX_TIME))

enum quality {
    PENDING = 0x00,
    GOOD    = 0x01,
    BAD     = 0x02
};

struct icecream_cone {
    enum quality approval_status;
    struct icecream_cone *next_request;
};

uint32_t open_store();
void *manager(void *args);
void *customer(void *args);
void *clerk(void *args);
void *cashier(void *args);

#endif