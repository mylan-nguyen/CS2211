/* CS2211a 2021 */
/* Assignment 02 */
/* Mylan Nguyen */
/* October 6, 2021 */ 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// set the number of iterations
#define ITERATIONS 3

#define DEBUG 0
#define DEBUG2 0

int main()
{
    // display the assignment number
    printf("Assignment Two\n\n");

    // initialize the generator
    srand(time(NULL));

    /* select random size of the array between 50 and 50 times the number of iterations */
    // define lower and upper of the range
    int lower = 50, upper = (50*ITERATIONS);

    // define array size 
    int arraySize = (rand() % (upper - lower + 1)) + lower;
    
    // print out the randomly determined size of the array to be used 
    // throughout the rest of the program
    printf("\tValue of random size of array: %d\n", arraySize);


    // create an array
    int array[arraySize];

    

    // determine the size of the array in bytes
    size_t sizeBytes = sizeof(array);

    // print out how many bytes this array will use based on the architecture 
    // of the O/S the program is currently being executed
    printf("\tSize of array: %zu bytes\n", sizeBytes);

    

    // create a for loop to keep track of which iteration we are on
    for (int i = 1; i < ITERATIONS+1; i++)
    {   
        /* PART 1 */
        /* populate array with random numbers based on the value of the current iteration */

        // declare max of elements in array
        int range; 
        range = (int)(pow(10, ITERATIONS+1-i));

        printf("\n\nTHIS IS ITERATION NUMBER: %d of %d\n", i, ITERATIONS);
        
        //  display the upper range value of the random number generator for the values being inserted into the array
        #if DEBUG
            printf("Upper Range Value: %d\n", range);
        #endif

        /* PART 1 */
        printf("\n\tThis is the original array populated with values in the range of 1 and %d\n", range);

        // define number of elements present in an array    
        int arrayLength = sizeof(array)/sizeof(array[0]); 
        printf("\tNumber of elements in the original array is: %d\n\n", arrayLength);

        // print the elements in the array evenly spaced apart
        // create a for loop to fill in the array
        for (int element = 0; element < arraySize; element++)
        { 

            // define the lower and upper (min and max) of array range (upper decreases by factor of 10)
            int lower1 = 1, upper1 = range;

            // choose random element in range to fill array
            array[element] = (rand() % (upper1 - lower1 + 1)) + lower1;

            // print out elements evenly spaced
            if ( element % 16 == 0)
            {
                printf("\n");
            }
            printf("%8d", array[element]);
        }
        
        /* PART 2 */
        printf("\n\n");


        // create a for loop to find duplicates in the array
        for (int element = 0; element < arraySize; element++)
        {
            for ( int j = element+1; j < arraySize; j++)
            {   
                // If an element match is found and element does not equal zero
                if(array[element] == array[j] && array[element]!=0)
                {
                // display each time when matching values are found along with the indexes of the matching values
                #if DEBUG2
                    printf("The value of %d at array index [%d] and the value of %d at array index [%d] are the same.\n", array[element], element, array[j], j);
                #endif
                
                    // then remove the current duplicate element 
                    for( int k = j; k < arraySize; k++)
                    {
                        array[k] = array[k + 1];
                    }

                    // do not increment j if shifting of elements occur
                    j--;
                    array[arraySize-1] = 0;
                }
            }
            
        }
        printf("\n\tThis is the current state of the array with all duplicate values removed\n");
        

        //count number of zeros in the array
        int zeroCount = 0;
        for ( int i = 0; i < arraySize; i++)
        {
            if ( array[i] == 0) zeroCount++;
        } 
            
        // print number of elements with out zeroCount
        printf("\tNumber of unique (non-zero, non-duplicate) elements in the array is: %d\n\n", arraySize-zeroCount);

        // create a for loop to print the unique elements evenly spaced
        for ( int element = 0; element < arraySize; element++)
        {
            // do not print zeros
            if (array[element] != 0)
            {
                if (element % 16 == 0)
                {
                    printf("\n");
                }
            printf("%8d", array[element]);
            }
        }

        /* PART 3 */
        // sort the array in ascending order and then display the unique, non-zero elements of the array in sorted order, evenly spaced
        
        // create a for loop to bubble sort the array
        for(int i = 0; i < (arraySize-1); i++)
        {
            for(int j = 0; j < (arraySize-1-i); j++)
            {
                // keep zeros to the right
                // Last i elements is held already in place
                if( array[j] > array[j+1] && array[j]!= 0 && array[j+1] != 0)
                {   
                    // define temp to swap over elements
                    int temp  = array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                }
            }
         }
        
        printf("\n\n\tThese are the unique, non-zero elements in the array sorted in ascending order: \n");

        // create a for loop to print out elements evenly spaced
        for ( int element = 0; element < arraySize; element++)
        {
            if (array[element] != 0)
            {
                if (element % 16 == 0)
                {
                printf("\n");
                }
                printf("%8d", array[element]);
            }
        }
        printf("\n\n");

        // create line of dashes to divide information
        for(int i=0; i<100; i++) printf("-");

    }    
    return 0;
}
