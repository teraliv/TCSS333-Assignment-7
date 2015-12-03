// Linked List ADT

#ifndef LL
#define LL
#include "LinkedList.h"
#include "mallok.h"
#endif

Node *createList(void) {
    return NULL;
}

// Inserts alphabetically on name
void insert(List **list, char *p, int size, int free) {
    Node *scan, *back = NULL;
    Node *newNode = malloc(sizeof(Node));
    newNode->p = p;
    newNode->size = size;
    newNode->free = free;
    newNode->next = NULL;
    
    if (*list == NULL) // Insert the very first node to the list:
        *list = newNode;
    else {
        scan = *list;
        while (scan != NULL && scan->p < p) {
            back = scan;
            scan = scan->next;
        }
        if (scan == *list)
            insertAtBeginning(list, newNode);
        else if (scan == NULL) {       // insert at the end:
	      newNode->next = back->next;  //yeah, I know, its already NULL
	      back->next = newNode;
	    } else {                       // insert in the middle:
	      newNode->next = scan;
	      back->next = newNode;
	    }
    }
}


void insertAtBeginning(List **list, Node *n) {
    n->next = *list;
    *list = n;
}


void freeList(List *list) {
    if (list) {
        freeList(list->next);
        free(list);
    }
}






// Inserts alphabetically on name
// void insert(List **list, char *p, int size, int free) {
//     Node *scan, *back = NULL;
//     Node *newNode = malloc(sizeof(Node));
//     newNode->p = p;
//     newNode->size = size;
//     newNode->free = free;
//     newNode->next = NULL;
    
//     if (*list == NULL) // Insert the very first node to the list:
//         *list = newNode;
//     else {
//         scan = *list;
//         while (scan != NULL && scan->p < p) {
//             back = scan;
//             scan = scan->next;
//         }
//         if (scan == *list)
//             insertAtBeginning(list, newNode);
//         else {       // insert at the end:
//             newNode->next = back->next;  //yeah, I know, its already NULL
//             back->next = newNode;
//         }
//     }
// }