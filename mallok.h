#include <stdio.h>
#include <stdlib.h>

// exteranal variables
static void *mypool;
static int pool_current_size;
static int pool_allowed_size = 0;
static int freed = 0;

void create_pool(int size);
void *my_malloc(int size);
void my_free(void *block);

void printPool();
int findEqualSize(List **l, int size);
int findGreaterSize(List **l, int size);


#ifndef HEADERFILE_H
#define HEADERFILE_H
#include "mallok.c"
#endif 