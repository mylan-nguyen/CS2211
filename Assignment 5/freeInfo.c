/* CS2211a 2021 */
/* Assignment 5 */
/* Mylan Nguyen */
/* 251155416 */
/* mnguy246 */
/* Dec 1, 2021 */

#include "headers.h"

void freeInfo(LIST* list) {
    // declare newPointer
    NODE* newPointer;
    // while the list is not empty
    while(list->head != NULL) {
        // set the newPointer as the head
        newPointer = list->head;
        // set the head to the next of the head
        list->head = list->head->next;
        // free the document pointer
        free(newPointer->dataPtr);
        // free the node pointer
        free(newPointer);
    }
    // free the list
    free(list);

}


