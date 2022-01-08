/* CS2211a 2021 */
/* Assignment 04 */
/* Mylan Nguyen */
/* November 10, 2021 */

#ifndef defHead
#define defHead

#define TOTALARRAY 0
#define COMBINEDARRAY 1
#define PRINTTOTALSORTED 2
void initArrays(int row, int column, int nArrs, int*** nTables) ;
void printArrays(int row, int column, int nArrs, int*** nTables, int index);
void combineArrays(int row, int column, int nArrs, int*** nTables);
void sortArrays(int** nTables, int row, int column);
//void freeArray(int row, int column, int nArrs, int*** nTables);

#endif
