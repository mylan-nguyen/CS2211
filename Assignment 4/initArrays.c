/* CS2211a 2021 */
/* Assignment 04 */
/* Mylan Nguyen */
/* November 10, 2021 */


#include "headers.h"
#include "definitions.h"

void initArrays(int row, int column, int nArrs, int ***nTables) {

    // initialize the generator
    srand(time(NULL));

    // Assign values to allocate memory
    // for every array in nTables
    for (int i = 0; i < nArrs; i++) {

        // makes space for the rows to hold single pointer
        nTables[i] = (int **) calloc (row, sizeof(int *));

        // for every row of the arrays
        for (int j = 0; j < row; j++) {

            // makes space for the column to hold address
            nTables[i][j] = (int *) calloc (column, sizeof(int));

            // for every column of the arrays
            for (int k = 0; k < column; k++) {
                // set each element in the last array to zero
                if (i == nArrs-1) {
                    nTables[i][j][k] = 0;
                    // print the arrays with unsorted values
                }else {
                    // Range of random integer between 1 and 10 times the total number of elements in the collection inclusive.
                    int lower = 1, upper = (nArrs*row*column*10);

                    // Define random array elements to populate each two dimensional array
                    int randElem = (rand() % (upper - lower + 1)) + lower;

                    nTables[i][j][k] = randElem;
                }
            }
        }
    }
}
