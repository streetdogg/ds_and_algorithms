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
                "\n6. Input and print a matrix."
                "\n7. Sum of Matrices."
                "\n8. Multiplication of Matrices."
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

        case 6: intput_and_display_matrix();
                break;

        case 7: sum_of_matrices();
                break;

        case 8: matrix_multiplication();
                break;

        default:
                break;
        }
    } while(choice);

    return 0;
}