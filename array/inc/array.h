#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>

#define MAX_ARRAY_SIZE 10
#define MAX_MAT_ROW 3
#define MAX_MAT_COL 4

/*
 * Reads array elements from the user and then prints them out.
 */
void read_and_display();

/*
 * Find the smallest and the largest number is the array user provided.
 */
void smallest_largest();

/*
 * Reverse and array
 */
void reverse();

/*
 * Pass each array element to another function
 */
void check_val(int num);

/*
 * Pass an array element to another function.
 */
void pass_element_to_function();

/*
 * Prints an array being passed.
 */
void print_array(int array[], int size);

/*
 * Passes the entire array to a function.
 */
void pass_array_to_function();

/*
 * Print Matrix.
 */
void print_matrix(int array[MAX_MAT_ROW][MAX_MAT_COL]);

/*
 * Input and display a matrix.
 */
void intput_and_display_matrix();

/*
 * prints Sum of matrices.
 */
void sum_of_matrices();

/*
 * prints Multiplication of matrices.
 */
void matrix_multiplication();

#endif