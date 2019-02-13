#include "sorts.h"

int main(){
    #include "unsorted_array.h"

    insertion_sort(unsorted_array, 100);

    for (int i=0; i<100; i++){
        printf ("%d ", unsorted_array[i]);
    }

    printf("\n");

    return 0;
}