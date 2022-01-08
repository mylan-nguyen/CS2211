/* CS2211a 2021 */
/* Assignment 5 */
/* Mylan Nguyen */
/* 251155416 */
/* mnguy246 */
/* Dec 1, 2021 */

#include "headers.h"


int main(void) {
    // Local Definitions
    srand(time(NULL));
    LIST* sList;
    sList = createList();

    // set document number to start at 1
    int documentNumber = 1;
    int cycles = 0;
    // define document and printingDocument of type DOCUMENT as NULL
    DOCUMENT* document = NULL;
    DOCUMENT* printingDocument = NULL;
    // Loop using 10% chance and 10 ITERATIONS
    for (int i = 0; i < ITERATIONS; i++) {
        int randomValue = (rand() % 10) + 1;

        // take 1 as the chance to get 1/10 is 10%
        if (randomValue == 1) {
            // allocate space for the document
            document = (DOCUMENT*)malloc(sizeof(DOCUMENT));
            // set document number
            document->number = documentNumber;
            // create a document calling createDocument function
            document = createDocument(document);
            // insert document into list using sorted function
            insertSortedList(sList, document);
            // increment document number for document added
            documentNumber++;
        }
        // if there is no job printing at the moment, aka printingDocument = NULL
        if (printingDocument == NULL && sList->count != 0) {
            // print job into printer
            printingDocument = dequeue(sList);
            cycles = reportCycles(printingDocument->cycles, printingDocument);
        }

        // case if the print job is being print
        if (printingDocument != NULL) {
            // decrement the number of pages by the value in PAGESPERMINUTE
            printingDocument->pages = printingDocument->pages - PAGESPERMINUTE;
            if (DEBUG_PRINT_PROCESS == true)
                printf("PRINTING - DOCUMENT:    %d PAGE :   %d priority : %d\n", printingDocument->number, printingDocument->pages, printingDocument->priority);

            // if there is zero or less pages in the document, done printing
            if (printingDocument->pages <= 0) {
                printf("Print Job Completed - Document Number:    %6d   -   Cycle Count:    %5d\n", printingDocument->number, cycles);
                // reset document to print next document in queue
                printingDocument = NULL;
            }
        }

        // print the updated queue
        printDocumentList(sList);

        // call maxCycles to update cycle
        maxCycles(sList);


    }

    printf("\nEnd of Program - *MYLAN NGUYEN*\n");
    printf("Number of printer jobs left in queue : %d\n", sList->count);


    // free memory
    freeInfo(sList);
    return 0;
}
