/* CS2211a 2021 */
/* Assignment 04 */
/* Mylan Nguyen */
/* November 10, 2021 */

#include "definitions.h"

void combineArrays(int row, int column, int nArrs, int*** nTables) {

    // Created a nest for loop to go through the same row and column of each array and add up total for each position
    for (int i = 0; i < nArrs; i++) {
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < column; k++) {
                // add the values inside the same position to the value in the last array
                nTables[nArrs-1][j][k] = nTables[nArrs-1][j][k] + nTables[i][j][k];
            }
        }
    }
    for (int j = 0; j < row; j++) {
        for (int k = 0; k < column; k++) {
            nTables[nArrs - 1][j][k] = ((nTables[nArrs - 1][j][k]) / 2);
        }
    }
}

