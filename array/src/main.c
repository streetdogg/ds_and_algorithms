/*
 * Various programs relating to Array
 */

#include <stdio.h>

#define MAX_ARRAY_SIZE 10

/*
 * Reads array elements from the user and then prints them out.
 */
void read_and_display(){
    int array[MAX_ARRAY_SIZE];

    for (int i=0; i<MAX_ARRAY_SIZE; i++){
        printf("Enter an element: ");
        scanf("%d", &array[i]);
    }

    printf("Printing Array\n");
    for (int i=0; i<MAX_ARRAY_SIZE; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
}

/*
 * Find the smallest and the largest number is the array user provided.
 */
void smallest_largest(){
    int array[MAX_ARRAY_SIZE];
    int small, large;

    for (int i=0; i<MAX_ARRAY_SIZE; i++){
        printf("Enter an element: ");
        scanf("%d", &array[i]);
    }

    small = large = array[0];
    for (int i=0; i<MAX_ARRAY_SIZE; i++){
        if (array[i] < small){
            small = array[i];
        } else if (array[i] > large){
            large = array[i];
        }
    }

    printf("Smallest: %d, Largest: %d\n", small, large);
}

/*
 * Reverse and array
 */
void reverse(){
    int array[MAX_ARRAY_SIZE];

    for (int i=0; i<MAX_ARRAY_SIZE; i++){
        printf("Enter an element: ");
        scanf("%d", &array[i]);
    }

    for (int i=0, j=MAX_ARRAY_SIZE-1; i<j; i++, j--){
        array[i] ^= array[j];
        array[j] ^= array[i];
        array[i] ^= array[j];
    }

    printf("Printing Array\n");
    for (int i=0; i<MAX_ARRAY_SIZE; i++){
        printf("%d ", array[i]);
    }
}

/*
 * Pass each array element to another function
 */
void check_val(int num){
    (num%2) ? printf("Number is odd!\n"): printf("Number is even!\n");
}

/*
 * Pass an array element to another function.
 */
void pass_element_to_function(){
    int array[MAX_ARRAY_SIZE];

    for (int i=0; i<MAX_ARRAY_SIZE; i++){
        printf("Enter an element: ");
        scanf("%d", &array[i]);
        check_val(array[i]);
    }
}

/*
 * Prints an array being passed.
 */
void print_array(int array[], int size){
    for (int i=0; i<size; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
}

/*
 * Passes the entire array to a function.
 */
void pass_array_to_function(){
    int array[MAX_ARRAY_SIZE];

    for (int i=0; i<MAX_ARRAY_SIZE; i++){
        printf("Enter an element: ");
        scanf("%d", &array[i]);
    }

    print_array(array, MAX_ARRAY_SIZE);
}

int main(){
    int choice;

    do {
        printf("\nChoose one of the following:"
                "\n1. Read and print an array."
                "\n2. Find smallest and largest."
                "\n3. Reverse."
                "\n4. Pass Array elements to function."
                "\n5. Pass entire Array to a function."
                "\n0. Exit."
                "\nChoice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1: read_and_display();
                break;
        case 2: smallest_largest();
                break;
        case 3: reverse();
                break;
        case 4: pass_element_to_function();
                break;
        case 5: pass_array_to_function();
                break;
        default:
                break;
        }
    } while(choice);

    return 0;
}