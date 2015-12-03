#include <stdio.h>
#include "LinkedList.h"
#include "mallok.h"

void test1();
void test2();
void test3();
void test4();
void printHeap();


int main() {
    
    create_pool(1000);
    list = createList();

    // test1();
    // test2();
    // test3();
    test4();


    





    
    
    return 0;
}

void printHeap() {
    Node *scan = list;

    while(scan != NULL) {
        printf("%p\n", scan->p);
        printf("%d\n", scan->size);
        printf("%d\n", scan->free);
        printf("-------------\n");
        scan = scan->next;
    }
}

void test4() {
    void *p1 = my_malloc(200);
    void *p2 = my_malloc(200);
    void *p3 = my_malloc(200);
    void *p4 = my_malloc(200);
    void *p5 = my_malloc(200);

    char *pnt = list->p;
    char *pnt2 = list->p;
    char *pnt3 = list->next->p;
    char *pnt4 = list->next->p;


    for (int i = 0; i < list->size; i++, pnt++) {
        *pnt = 'A';
    }

    for (int i = 0; i < list->next->size; i++, pnt3++) {
        *pnt3 = 'B';
    }

    for (int i = 1; i <= list->size; i++, pnt2++) {
        printf("%c", *pnt2);
        if (i % 20 == 0)
            printf("\n");
    }

    for (int i = 1; i <= list->next->size; i++, pnt4++) {
        printf("%c", *pnt4);
        if (i % 20 == 0)
            printf("\n");   
    }
}

void test3() {
    void *p1 = my_malloc(200);
    void *p2 = my_malloc(200);
    void *p3 = my_malloc(200);
    void *p4 = my_malloc(200);
    void *p5 = my_malloc(200);

    my_free(p3);

    my_malloc(210);
    
    my_malloc(150);
    printHeap();
    my_malloc(60);
    my_malloc(50);
    printHeap();
}

void test2() {
    void *p1 = my_malloc(200);
    void *p2 = my_malloc(50);
    void *p3 = my_malloc(200);
    void *p4 = my_malloc(350);
    void *p5 = my_malloc(200);

    
    my_free(p2);
    my_free(p4);
    
    void *p6 = my_malloc(50);
    void *p7 = my_malloc(200);
    void *p8 = my_malloc(100);

    printHeap();
}

void test1() {
    void *p1 = my_malloc(200);
    void *p2 = my_malloc(200);
    void *p3 = my_malloc(200);
    void *p4 = my_malloc(200);
    void *p5 = my_malloc(200);
    

    printf("used heap: %d\n", pool_current_size);

    printf("%p\n", p1);
    printf("%p\n", p2);
    printf("%p\n", p3);
    printf("%p\n", p4);
    printf("%p\n", p5);

    
    my_free(p1);
    my_free(p2);
    my_free(p3);
    my_free(p4);
    my_free(p5);
    
    void *p6 = my_malloc(200);
    void *p7 = my_malloc(200);
    void *p8 = my_malloc(200);
    void *p9 = my_malloc(200);
    void *p0 = my_malloc(200);
    
    printf("-----------\n");
    printf("%p\n", p6);
    printf("%p\n", p7);
    printf("%p\n", p8);
    printf("%p\n", p9);
    printf("%p\n", p0);

    my_free(p6);
    my_free(p7);
    my_free(p8);
    my_free(p9);
    my_free(p0);
    
    void *p11 = my_malloc(200);
    void *p12 = my_malloc(200);
    void *p13 = my_malloc(200);
    void *p14 = my_malloc(200);
    void *p15 = my_malloc(200);
    
    printf("-----------\n");
    printf("%p\n", p11);
    printf("%p\n", p12);
    printf("%p\n", p13);
    printf("%p\n", p14);
    printf("%p\n", p15);

    
    // printf("%p\n", p);
    // printf("%p\n", p1);
    // printf("%p\n", list->next->next->next->p);


    // printf("%p\n", p);
    // printf("%p\n", p1);
    // printf("%p\n", list->next->next->next->p);

}