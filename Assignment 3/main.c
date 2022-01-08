/* CS2211a 2021 */
/* Assignment 03 */
/* Mylan Nguyen */
/* October 19, 2021 */

#include <stdio.h>
#include <stdlib.h>

#define ASIZE 10

/* Swap by reference function declaration */
void swap_by_reference(int * num1, int * num2);
/* Swap by value function declaration */
void swap_by_value(int   num1, int  num2);
/* Function declaration to print array */
void printArray(int arr[]);

int main()
{

    printf("\n------------ASSIGNMENT THREE (3) CS2211a----- MYLAN NGUYEN -----------\n\n");

// --------------------------------------------------------------------------------------------
// part one (1)
// simple declaration and definition of a pointer variable
// display memory addresses


    int num = 10;
    int *ptr;

    // Stores the address of num to pointer type
    ptr = &num;

    printf("\n\n---- PART ONE (1) ----------------------------------------------------\n\n");

// If these printout statements display a compiler warning: format XXXX expects argument type..'
// ignore this warning. THe purpose is to diaplay the value in specified format(s)
    printf("This is Part One (1): Pointer Declaration and Definition.\n\n");
    printf("Address of num: \nin decimal: %d\nin hex: %x\nas a pointer: %p\n",ptr,ptr,ptr);
    printf("Value stored in the variable num = %d\n\n", *ptr);

    printf("Address of ptr: \nin decimal: %d\nin hex: %x\nas a pointer: %p\n",&ptr,&ptr,&ptr);
    printf("Value stored in the variable ptr = %p\n", ptr);
    printf("Value pointed by ptr = %d\n", *ptr);

// --------------------------------------------------------------------------------------------
// part two (2)
// use pointer variables to create basic equations of addition, subtraction, multiplication and division
    float fnum1, fnum2;    // Normal variables
    float *ptr1, *ptr2;  // Pointer variables

    float sum, diff, mult, div;

    ptr1 = &fnum1; // ptr1 stores the address of fnum1
    ptr2 = &fnum2; // ptr2 stores the address of fnum2

    printf("\n\n---- PART TWO (2) ----------------------------------------------------\n\n");

    printf("This is Part Two (2): Basic example of using pointers in equations.\n\n");

    // User input using the two pointers to floating variables: *ptr1, *ptr2
    printf("Enter any two real numbers and then hit <Enter>: ");
    scanf("%f%f", ptr1, ptr2);

    // Perform arithmetic operation using pointer refrences only
    sum  = (*ptr1) + (*ptr2);
    diff = (*ptr1) - (*ptr2);
    mult = (*ptr1) * (*ptr2);
    div  = (*ptr1) / (*ptr2);

    // Print the results
    printf("Sum = %.2f\n", sum);
    printf("Difference = %.2f\n", diff);
    printf("Product = %.2f\n", mult);
    printf("Quotient = %.2f\n", div);


// --------------------------------------------------------------------------------------------
// part three (3)
// function calls, passing by value and passing by reference using pointer variables
    
	int inum1, inum2;

    printf("\n\n---- PART THREE (3) ---------------------------------------------------\n\n");

    printf("This is Part Three (3): Pointer use in function calls.\n\n");
    // Input numbers
    printf("Enter two non-identical numbers and then hit <Enter>: ");
    scanf("%d%d", &inum1, &inum2);

    // Print original values of num1 and num2
    printf("Before swapping ( values in <main> function )\n");
    printf("Value of num1 = %d \n", inum1);
    printf("Value of num2 = %d \n\n", inum2);

    // Pass the values of num1 and num2
    swap_by_value(inum1, inum2);

    // Print the swapped values of num1 and num2
    printf("After swapping ( values in <main> function )\n");
    printf("Value of num1 = %d \n", inum1);
    printf("Value of num2 = %d \n\n", inum2);
	
    // Pass the addresses of num1 and num2
    swap_by_reference(&inum1, &inum2);

    // Print the swapped values of num1 and num2
    printf("After swapping ( values in <main> function )\n");
    printf("Value of num1 = %d \n", inum1);
    printf("Value of num2 = %d \n", inum2);


// --------------------------------------------------------------------------------------------
// part four (4)
// Initialize an array and then print the array using only pointer(s)

    int arr[ASIZE];
    int  i4;
    int *ptr4 = arr;    // Pointer to arr[0]

    for (i4 = 0; i4 < ASIZE; i4++)
    {
        *(ptr4 + i4) = i4;

        // Move pointer to next array element
        *(ptr4+i4);
    }

    // Make sure that pointer again points back to first array element
    ptr4 = arr;

    printf("\n\n---- PART FOUR (4) ----------------------------------------------------\n\n");

    printf("This is Part Four (4): Array element manipulation using Pointers.\n\n");

    printf("Array elements: ");
    printArray(arr);


// --------------------------------------------------------------------------------------------
// part five (5)
// Initialize an array using only pointers
// then copy the contents of the first array (source) into a second array (destination)
    int source_arr[ASIZE], dest_arr[ASIZE];
    int  i5;

    int *source_ptr = source_arr;   // Pointer to source_arr
    int *dest_ptr   = dest_arr;     // Pointer to dest_arr

    int *end_ptr;


    for (i5 = 0; i5 < ASIZE; i5++)
    {
        // initialize each array element in source_arr only using pointer arithmetic (not array indexes)
        *(source_ptr + i5) = i5;
    }


    // Pointer to last element of source_arr
    end_ptr = &source_arr[ASIZE - 1];

    printf("\n\n\n---- PART FIVE (5) ----------------------------------------------------\n\n");

    printf("This is Part Five (5): Array manipulation using pointer refrencing.\n\n");

    // Print source and destination array before copying
    printf("\nSource array before copying: ");
    printArray(source_arr);

    printf("\nDestination array before copying: ");  // indeterminate output since dest_arr has not been initialized
    printArray(dest_arr);



// Write the code that will copy the contents of the original array (source) into the
// the second array (destination) in the same order using only pointers
// contents of source array: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
// after copy - the contents of destination array will be:
//           0, 1, 2, 3, 4, 5, 6, 7, 8, 9
// notice: no comma after the last value

    while(source_ptr <= end_ptr)
    {
        *dest_ptr = *source_ptr;
        // Increment source_ptr and dest_ptr
        source_ptr++;
        dest_ptr++;
    }

    // Print source and destination array after copying
    printf("\n\nSource array after copying: ");
    printArray(source_arr);

    printf("\nDestination array after copying: ");
    printArray(dest_arr);


// --------------------------------------------------------------------------------------------
// part six (6)
// Copy the contents of the original array (source) from part five (5) into the
// the second array (destination) in reverse order using only pointers


    // Pointer to last element of source_arr using the correct array index
    source_ptr = &source_arr[ASIZE - 1];
    // Pointer to the first element of dest_arr using the correct array index
    dest_ptr   = &dest_arr[0];
    i5 = ASIZE;

// Write the code that will copy contents of source array into destination array in reverse order:
// source array: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
// after reverse copy
// destination array:  9, 8, 7, 6, 5, 4, 3, 2, 1, 0
// notice: no comma after the last value

    for (int i = 0; i < ASIZE; i++) {
        *(dest_ptr + i) = *(source_ptr - i);
    }

    printf("\n\n---- PART SIX (6) ----------------------------------------------------\n\n");

    printf("This is Part Six (1): Pointer use to reverse an array.\n\n");

    // Print source and destination array after reversing
    printf("Source array after reversing: ");
    printArray(source_arr);

    printf("\nDestination array after reversing: ");
    printArray(dest_arr);

    printf("\n----------------------------------------------------------------------\n\n");
	
    printf("\n------------ASSIGNMENT THREE (3) CS2211a----- MYLAN NGUYEN -----------\n\n");
    return 0;
}

/**
 * Function to swap two numbers
 */
void swap_by_value(int num1, int  num2)
{
    int temp;

    // Copy the value of num1 to some temp variable
    temp = num1;

    // Copy the value of num2 to num1
    num1= num2;

    // Copy the value of num1 stored in temp to num2
    num2= temp;

    printf("After swapping ( values in <swap by value> function )\n");
    printf("Value of num1 = %d \n", num1);
    printf("Value of num2 = %d \n\n", num2);
}

void swap_by_reference(int  *num1, int  *num2)
{
    int temp;

    // Copy the value of num1 to some temp variable
    temp = *num1;

    // Copy the value of num2 to num1
   *num1= *num2;

    // Copy the value of num1 stored in temp to num2
    *num2= temp;

    printf("After swapping ( values in <swap by reference> function )\n");
    printf("Value of num1 = %d \n", *num1);
    printf("Value of num2 = %d \n\n", *num2);
}

void printArray(int *arr)
{
    int i;

// Write the code that will print out the contents of the passed in array
// using only pointer refrence and not array indexes
// notice: no comma after the last value

    for (i = 0; i < ASIZE; i++) {
        printf("%d", *(arr + i));
        if (i < ASIZE-1) {
            printf(", ");
        }
    }
}
