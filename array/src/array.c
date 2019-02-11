#include "array.h"

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

/*
 * Print Matrix.
 */
void print_matrix(int array[MAX_MAT_ROW][MAX_MAT_COL]){
    for (int i=0; i<MAX_MAT_ROW; i++){
        for (int j=0; j<MAX_MAT_COL; j++){
            printf("%d ", array[i][j]);
        }

        printf("\n");
    }
}

/*
 * Input and display a matrix.
 */
void intput_and_display_matrix(){
    int array[MAX_MAT_ROW][MAX_MAT_COL];

    for (int i=0; i<MAX_MAT_ROW; i++){
        for (int j=0; j<MAX_MAT_COL; j++){
            printf("Give me an array element: ");
            scanf("%d", &array[i][j]);
        }
    }

    print_matrix(array);
}

/*
 * prints Sum of matrices.
 */
void sum_of_matrices(){
    int mat_1[MAX_MAT_ROW][MAX_MAT_COL] = {{1,2,3,4},{5,6,7,8},{9,0,1,2}};
    int mat_2[MAX_MAT_ROW][MAX_MAT_COL] = {{1,2,3,4},{5,6,7,8},{9,0,1,2}};
    int result[MAX_MAT_ROW][MAX_MAT_COL];

    for (int i=0; i<MAX_MAT_ROW; i++){
        for (int j=0; j<MAX_MAT_COL; j++){
            result[i][j] = mat_1[i][j] + mat_2[i][j];
        }
    }

    print_matrix(result);
}

/*
 * prints Multiplication of matrices.
 */
void matrix_multiplication(){
    int mat_1[MAX_MAT_ROW][MAX_MAT_COL] = {{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    int mat_2[MAX_MAT_ROW][MAX_MAT_COL] = {{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    int result[MAX_MAT_ROW][MAX_MAT_COL] = {0};

    for (int i=0; i<MAX_MAT_COL; i++){
        for (int j=0; j<MAX_MAT_ROW; j++){
            for (int k=0; k<MAX_MAT_ROW; k++){
                result[k][i] += mat_1[k][i] * mat_2[j][i];
            }
        }
    }

    print_matrix(result);
}