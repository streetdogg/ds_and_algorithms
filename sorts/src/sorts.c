#include "sorts.h"

/*
 * Insertion Sort
 */
void insertion_sort(int *array, int length) {
    int key, i, j;

    for (i=1; i<length; i++) {
        key = array[i];

        for (j=i-1; array[j]>key && j>=0; j--) {
            array[j+1] = array[j];
        }

        array[j+1] = key;
    }
}

/*
 * Bubble Sort
 */
void bubble_sort(int *array, int length) {
    for (int i=length-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (array[j] > array[j+1]){
                array[j]   ^= array[j+1];
                array[j+1] ^= array[j];
                array[j]   ^= array[j+1];
            }
        }
    }
}

/*
 * Selection sort
 */
void selection_sort(int *array, int length) {
    int pivot, min;

    for (pivot=0; pivot < length-1; pivot++) {

        min = pivot;

        for (int i=pivot; i<length; i++) {
            if (array[i] <= array[min]){
                min = i;
            }
        }

        // swap if min is different than pivot
        if (pivot != min){
            array[pivot]   ^= array[min];
            array[min]     ^= array[pivot];
            array[pivot]   ^= array[min];
        }
    }
}