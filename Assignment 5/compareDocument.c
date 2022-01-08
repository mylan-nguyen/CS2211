/* CS2211a 2021 */
/* Assignment 5 */
/* Mylan Nguyen */
/* Dec 1, 2021 */

#include "headers.h"


// =================== compareTo ====================
// helper function to compare each document in queue for insert to correct spot in queue
int compareTo(DOCUMENT* document1, DOCUMENT* document2) {
    // define priorities of each document
    int priority1 = document1->priority;
    int priority2 = document2->priority;
    // define page number of each document
    int page1 = document1->pages;
    int page2 = document2->pages;

    // if doc1 priority is lower (Ex: priority 3 is lower than priority 1) then return 1
    if (priority1 > priority2)
        return 1;
        // if doc1 priority is higher (Ex: priority 1 is higher than priority 3) then return -1
    else if (priority1 < priority2)
        return -1;
        // case for same priority level (priority level is equal), compare page numbers
    else {
        // if doc1 has more pages than doc2, return 1
        if (page1 > page2)
            return 1;
            // if doc1 has less pages than doc2, return -1
        else if (page1 < page2)
            return -1;
            // if doc1 has the same number of pages as doc2, return 0
        else
            return 0;
    }
}
