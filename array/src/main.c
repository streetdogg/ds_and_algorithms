/*
 * Various programs relating to Array
 */

#include "array.h"

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