#ifndef HEADERFILE_H
#define HEADERFILE_H
#include "mallok.h"
#include "LinkedList.h"
#endif

void create_pool(int size) {
    mypool = malloc(size * sizeof(void));
    pool_allowed_size = size;
}

void printPool() {
    printf("p2: %p\n", mypool);
}

void *my_malloc(int size) {
    
    List *l = list;
    void *p;
    int foundEqual = 0;
    int foundLarge = 0;

    // all heap space is available
    if (pool_current_size == 0) {
        p = mypool;
    	insert(&list, p, size, 0);
    	pool_current_size += size;
	}
    
    // next available space
    else if ((pool_current_size + size) <= pool_allowed_size) {
        p = mypool + pool_current_size;
        insert(&list, p, size, 0);
        pool_current_size += size;
    }
    
    // use freed space from node
    else if (freed) {
    	
    	foundEqual = findEqualSize(&l, size);
    	
    	
    	if (!foundEqual) {
    		l = list;
    		foundLarge = findGreaterSize(&l, size);
    	}
		
		
    	
		
		if (foundEqual) {
			l->free = 0;
    		p = l->p;
    	}
    	
    	if (foundLarge) {
    		p = l->p + (l->size - size);
    		insert(&list, p, size, 0);
    		l->size = l->size - size;
    	}

    	if (!foundEqual && !foundLarge)
    		p = NULL;
    	
    }
    
    // no heap space are left
    else
        p = NULL;

    
    if (p == NULL)
    	printf("No heap space is available!\n");

    
    return p;
}


void my_free(void *block) {
	List *l = list;

	while (l->p != block) {
		l = l->next;
	}
	l->free = 1;
	freed = 1;

	// printf("%p\n", l->p);
	// printf("%d\n", l->size);
	// printf("%d\n", l->free);

}


int findEqualSize(List **l, int size) {
	int found = 0;

	while (*l != NULL && !found) {
		
		if ((*l)->free && (*l)->size == size) {
			found = 1;
			// printf("found\n");
		} else
			*l = (*l)->next;
	}

	return found;
}


int findGreaterSize(List **l, int size) {
	int found = 0;
	
	// while ((*l)->free == 0 || !found) {
	while (*l != NULL && !found) {
		if ((*l)->free && (*l)->size > size) {
    		found = 1;
    		// printf("found larger\n");
    	}
	    else
		    *l = (*l)->next;
	}

	
	return found;
}




// int findGreaterSize(List **l, void **p, int size) {
// 	int found = 0;
// 	List *k;
// 	void *s;

// 	while (!found) {
// 		if ((*l)->size > size) {
//     		found = 1;
// 	    } else
// 		    (*l) = (*l)->next;
// 	}

// 	k = *l;

// 	*p = k->p + (k->size - size);
// 	k->size = k->size - size;
// 	printf("pq: %p\n", p);
// 	s = *p;

// 	insert(&list, s, size, 0);

// 	return found;
// }

// use freed space from node
    // else if (freed) {
    // 	// find nodes with free heap
    // 	while (!l->free && (l->size > size)) {
    // 		l = l->next;
    // 		if (l->size > size)
    // 			printf("Larger size");
    // 	}
    // 	printf("%d\n", l->size);
    // 	printf("%p\n", l->p);
    // 	if (l->size == size) {
    // 		l->free = 0;
    // 		p = l->p;
    // 	}
    // 	else
    // 		p = NULL;
    // }







// while ((*l)->free == 0 || !found) {
	// 	if ((*l)->free && (*l)->size == size) {
 //    		found = 1;
	//     } else
	// 	    (*l) = (*l)->next;
	// }
	// if (found)
	// 	printf("FOUND EQUAL\n");


// int findGreaterSize(List **l, int size) {
// 	int found = 0;
	
// 	printf("XXX");
// 	// while (!found) {
// 	while ((*l)->free == 0 || !found) {
// 		if ((*l)->size > size) {
//     		found = 1;
// 	    } else
// 		    (*l) = (*l)->next;
// 	}

	
// 	return found;
// }
