/* CS2211a 2021 */
/* Assignment 04 */
/* Mylan Nguyen */
/* November 10, 2021 */

#include "definitions.h"

void sortArrays(int **nTables, int row, int column) {
    // iterate through the row
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            // for every row in array
            for (int k = 0; k < row; k++) {
                // for every column in row
                for (int l = 0; l < column; l++) {
                    // compare the two values for sorting
                    if (nTables[i][j] < nTables[k][l]) {
                        // swap element if the contents is greater than current
                        int temp = nTables[i][j];
                        nTables[i][j] = nTables[k][l];
                        nTables[k][l] = temp;
                    }
                }
            }
        }
    }
}
