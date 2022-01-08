/* CS2211a 2021 */
/* Assignment 5 */
/* Mylan Nguyen */
/* Dec 1, 2021 */

#include "headers.h"

// =================== createList ====================
LIST* createList(void)
{
    // create list
    LIST* list;
    // allocate space for list
    list = (LIST*)malloc(sizeof(LIST));
    if (list)
    {
        // set head to null
        list->head = NULL;
        // set count to 0
        list->count = 0;
    }
    return list;
}

// =================== insertSortedList ====================
// function to insert list in correct order
bool insertSortedList(LIST* list, void* itemPtr) {
    // create a newPtr
    NODE* newPtr;
    // ensure that space is allocated for newPtr
    if (!(newPtr = (NODE*)malloc(sizeof(NODE))))
        return false;
    // put item Document into the data Node Pointer
    newPtr->dataPtr = itemPtr;
    // increment count of linked list for inserting a new node
    (list->count)++;
    // check case when linked list is empty
    if (list->head == NULL) {
        // set next of newPtr to null
        newPtr->next = NULL;
        // make the newPtr the head of list
        list->head = newPtr;
        return true;
    }

    // Compare new doc with first doc in linked list
    NODE* current = list->head;
    //if itemPtr is less than current
    if (compareTo(itemPtr, current->dataPtr) < 0) {
        // set next of newPtr to current node
        newPtr->next = current;
        // make new node the head node
        list->head = newPtr;
        return true;
    }

    // create node previous that is the head of the linked list
    NODE* previous = current;
    while (current != NULL) {
        //if itemPtr is less than current
        if (compareTo(itemPtr, current->dataPtr) < 0) {
            //Find the spot where node should be added in between in the linked list
            // set next of newPtr to current
            newPtr->next = current;
            // set next of previous to newPtr
            previous->next = newPtr;
            return true;
        }
        // set previous to current
        previous = current;
        // set next of current to current
        current = current->next;
    }

    // add newPtr to the end of linked list, when current is null
    previous->next = newPtr;
    // set newPtr next to null
    newPtr->next = NULL;
    return true;
}

// =================== dequeue ====================
// function to pop of first item in the linked list to print page by page
DOCUMENT * dequeue(LIST* list) {
    // case if queue is empty, do not pop
    if (list->count == 0) {
        return NULL;
    }
    // if linked list is not empty
    else {
        // set node to head of list
        NODE* node = list->head;
        // create node of type document to be the document to be printed
        DOCUMENT* toPrintDocument = node->dataPtr;
        // set head of list to the next to pop document to be printed
        list->head = node->next;
        // since popped, must free node
        free(node);
        // decrement count in queue since document has been popped
        (list->count)--;
        return toPrintDocument;
    }
}

// =================== maxCycles ====================
void maxCycles(LIST* list) {
    if (list->count == 0 )
        return;

    // make the first printer node the current node loop until done
    NODE* myPtr = list->head;

    while (myPtr != NULL) {

        // increment the cycle count by 1
        ((DOCUMENT*)(myPtr->dataPtr))->cycles++;

        if (DEBUG_SHOW_CYCLES == true)
            printf("Increment Cycle - Document: %4d     Pages: %4d     Priority: %4d     Cycle Count: %4d\n", ((DOCUMENT*)(myPtr->dataPtr))->number, ((DOCUMENT*)(myPtr->dataPtr))->pages,
                   ((DOCUMENT*)(myPtr->dataPtr))->priority, ((DOCUMENT*)(myPtr->dataPtr))->cycles);



        if (((DOCUMENT*)(myPtr->dataPtr))->cycles == MAXCYCLES) {
            if (DEBUG_SHOW_EXCEEDED)
                printf("EXCEEDED CYCLE COUNT - Document:   %d    Pages:  %d    Priority: %d    Cycle Count: %d\n",
                    ((DOCUMENT *) (myPtr->dataPtr))->number, ((DOCUMENT *) (myPtr->dataPtr))->pages, ((DOCUMENT *) (myPtr->dataPtr))->priority, ((DOCUMENT *) (myPtr->dataPtr))->cycles);
            //((DOCUMENT *) (myPtr->dataPtr))->priority = 0;
        }
        myPtr = myPtr->next;
    }
}


// =================== reportCycles ====================
int reportCycles(int numOfCycles, DOCUMENT* printingDocument) {

    return numOfCycles + printingDocument->pages;

} // calculate number of cycles it takes to finish the printing of this current document
