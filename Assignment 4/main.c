/* CS2211a 2021 */
/* Assignment 04 */
/* Mylan Nguyen */
/* 251155416 */
/* mnguy246 */
/* November 10, 2021 */

#include "headers.h"

int main()
{
    int nArrs, row, column;
    int ***nTables;

    printf("\nEnter the number of arrays (0 to quit): ");
    scanf("%d", &nArrs);

    while ( nArrs != 0) {

        printf("\nEnter values for Rows, Columns (e.g.2 3): ");
        scanf("%d %d", &row, &column);

        // intialize triple pointer array
        nTables = (int ***) calloc (nArrs +1, sizeof(int **));

        // initialize the array with the user defined values
        initArrays(row, column, nArrs, nTables);

        // prints the unsorted collection of array not including the cumulative last array
        printArrays(row, column, nArrs, nTables, TOTALARRAY);

        // combine all the arrays in the collection by adding the totals of each element position into last array
        combineArrays(row, column, nArrs, nTables);

        // prints the last array with combined values, unsorted
        printArrays(row, column, nArrs, nTables, COMBINEDARRAY);

        // sorts values in array, ascending order
        sortArrays(nTables, row, column);

        // prints the last array with combined values, unsorted
        printArrays(row, column, nArrs, nTables, PRINTTOTALSORTED);

        printf("\nXXXXXX END OF SESSION XXXXXX\n\n");

        printf("Enter the number of arrays (0 to quit): ");
        scanf("%d", &nArrs);
    }

    // do to some errors, causing trouble running
    // freeArray(row, column, nArrs, nTables);

    return 0;

}
