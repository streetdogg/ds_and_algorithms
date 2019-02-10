#include <stdio.h>
#include "am.h"

extern unsigned int am[MAX][MAX];

struct direction {
    unsigned int from;
    unsigned int to;
};

unsigned int print_path(unsigned int from, unsigned int to) {
    if (from >= MAX || to >= MAX){
        return 0;
    }

    if (from == to){
        return 0;
    }

    if (am[from][to]==1){
        printf("%u",to);
        return 1;
    }

    for (unsigned int i=from; i<MAX; i++){
        for (unsigned int j=0; j<MAX; j++){
            if (i==j){
                continue;
            }

            if (am[i][j] == 1){
                if (print_path(j, to)){
                    printf(" <- %u",j);
                    return 1;
                }
            } else {
                continue;
            }
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    struct direction dir;
    printf("Starting point: ");
    scanf("%u", &dir.from);
    printf("Ending point: ");
    scanf("%u", &dir.to);

    if (print_path(dir.from, dir.to)){
        printf(" <- %u\n",dir.from);
        return 0;
    }

    printf("Oops! No path Exist!\n");
    return 1;
}