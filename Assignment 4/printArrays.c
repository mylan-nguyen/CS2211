/* CS2211a 2021 */
/* Assignment 04 */
/* Mylan Nguyen */
/* 251155416 */
/* mnguy246 */
/* November 10, 2021 */

#include "headers.h"
#include "definitions.h"


void printArrays(int row, int column, int nArrs, int ***nTables, int flag) {
    // check if flag equals 0, if so, only print arrays not including last array in table
    if (flag == 0) {
        // print out the values in the arrays
        // loop though the arrays in table
        for (int i = 0; i < nArrs; i++) {
            if (i == nArrs -1) {
                break;
            }
            printf("Array %d:\n", i+1);
            // for every row in the array
            for (int j = 0; j < row; j++) {
                // for every column in each row of the array
                for (int k = 0; k < column; k++) {
                    // print its value
                    printf("%9d  ", nTables[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    // if flag does not equal 0, print out all the elements of the last array
    else if (flag == 1) {
        printf("Array of Combined Totals based on 2 Arrays:\n");
        //creates a for loop to loop through the total amount of row
        for (int i = 0; i < row; i++) {
            //creates a for loop to loop through the total amount of column
            for (int j = 0; j < column; j++) {
                //prints the value of the array
                printf("%9d  ", nTables[nArrs-1][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    // if flag does not equal 0 or 1, print out all the elements of the last array in sorted ascending order
    else {
        printf("Combined Totals based on 2 Arrays Sorted Ascending:\n");
        //creates a for loop to loop through the total amount of row
        for (int i = 0; i < row; i++) {
            //creates a for loop to loop through the total amount of column
            for (int j = 0; j < column; j++) {
                //prints the value of the array
                printf("%9d  ", nTables[nArrs-1][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}