#include "sorts.h"

int main(){
    // Import the unsorted array
    #include "unsorted_array.h"

    int choice;

    printf("Please select a Sort:\n"
        "1. Insertion sort.\n"
        "2. Bubble sort.\n"
        "3. Selection sort.\n"
        "Choice: ");
    scanf("%d", &choice);

    switch(choice){
    case 1: insertion_sort(unsorted_array, 100);
            break;
    case 2: bubble_sort(unsorted_array, 100);
            break;
    case 3: selection_sort(unsorted_array, 100);
            break;
    default:
            break;
    }

    for (int i=0; i<100; i++){
        printf ("%d ", unsorted_array[i]);
    }
    printf("\n");

    return 0;
}