// Linked List Header file

#include <stdio.h>
#include <stdlib.h>
//#include "LinkedList.c"  //Not here! See below:

// Data type definitions
typedef struct node {
    char *p;
    int size;
    int free;
    struct node *next;
} Node, List;

// LinkedList prototypes
Node *createList(void);
void insert(List **, char *, int, int);
void insertAtBeginning(List **, Node *);
void freeList(List *);

#ifndef LL
#define LL
#include "LinkedList.c"
#endif 

static List *list;