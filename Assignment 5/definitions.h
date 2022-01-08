/* CS2211a 2021 */
/* Assignment 5 */
/* Mylan Nguyen */
/* Dec 1, 2021 */

#ifndef ASSIGN5_DEFINITIONS_H
#define ASSIGN5_DEFINITIONS_H

#define ITERATIONS 1000
#define MAXPAGES 30
#define MAXCYCLES 200
#define PRIORITYHIGH 1
#define PRIORITYAVERAGE 2
#define PRIORITYLOW 3
#define PAGESPERMINUTE 1


#define DEBUG_LIST 1
#define DEBUG_ADDING 1
#define DEBUG_PRINT_PROCESS 1
#define DEBUG_SHOW_CYCLES 1
#define DEBUG_SHOW_EXCEEDED 1

#include "headers.h"

typedef struct node
{
    void* dataPtr;
    struct node* next;
} NODE;

typedef struct list
{
    NODE* head;
    int count;
} LIST;


typedef struct document
{
    int number;
    int priority;
    int pages;
    int cycles;
} DOCUMENT;

// declare all functions

DOCUMENT* createDocument(DOCUMENT* document);

void printDocumentList(LIST* list);

LIST* createList(void);

bool insertSortedList(LIST* list, void* itemPtr);

DOCUMENT * dequeue(LIST* list);

void maxCycles(LIST* list);

int reportCycles(int numOfCycles, DOCUMENT* printingDocument);

int compareTo(DOCUMENT* document1, DOCUMENT* document2);

void freeInfo(LIST* list);

#endif //ASSIGN5_DEFINITIONS_H
