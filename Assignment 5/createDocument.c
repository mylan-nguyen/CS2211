/* CS2211a 2021 */
/* Assignment 5 */
/* Mylan Nguyen */
/* 251155416 */
/* mnguy246 */
/* Dec 1, 2021 */

#include "headers.h"


// =================== createDocument ====================
// Create a print job based on the frequency, priority distribution, and random number of pages
DOCUMENT* createDocument(DOCUMENT* document) {
    // Define variables
    int priority = 0, pages = 0, cycles = 0;
    // Create a random priority
    int randomPriority = (rand() % ((10) - 1 + 1) + 1);
    // 1 – high priority ( 10% probability )
    if (randomPriority == 1) {
        priority = PRIORITYHIGH;
    }
    // 3 – low priority ( 20% probability)
    else if (randomPriority == 2 || randomPriority == 3) {
        priority = PRIORITYLOW;
    }
    // 2 – average priority ( 70% probability )
    else {
        priority = PRIORITYAVERAGE;
    }
    // The number of pages will be a random number between 0 and MAXPAGES
    int randomPage = (rand() % ((MAXPAGES)-1 + 1) + 1);

    // Print details of document added to the queue
    if(DEBUG_ADDING == true)
        printf("\nAdding to Queue - Doc: %d NoPages : %d Priority : %d\n", document->number, randomPage, priority);

    document->priority = priority;
    // start at cycle 0
    document->cycles = 0;
    document->pages = randomPage;

    return document;
}



