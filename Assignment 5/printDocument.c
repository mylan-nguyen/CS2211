/* CS2211a 2021 */
/* Assignment 5 */
/* Mylan Nguyen */
/* Dec 1, 2021 */

#include "headers.h"


// =================== printDocumentList ====================
void printDocumentList(LIST* list) {

    // for case if queue has no print jobs in it
    if (list->count == 0) {
        if (DEBUG_LIST == true)
            printf("EMPTY QUEUE - no print jobs currently in queue\n");
        return;
    }

    if (DEBUG_LIST == true)
        printf("\nCurrent Printer Queue Size: %d\n", list->count);
    // create endNode that is the head of the list
    NODE* endNode = list->head;

    // while the endNode is not null
    while (endNode != NULL) {
        if (DEBUG_LIST == true )
            printf("Current Printer Queue : DocNum: %4d     NumofPages %4d     PriorityLevel %4d     NumOfCycles %4d\n", ((DOCUMENT*)(endNode->dataPtr))->number, ((DOCUMENT*)(endNode->dataPtr))->pages, ((DOCUMENT*)(endNode->dataPtr))->priority, ((DOCUMENT*)(endNode->dataPtr))->cycles);

        // link endNode to next node in queue
        endNode = endNode->next;
    }
    if (DEBUG_LIST == true)
        printf("END OF LIST\n\n");

}

