#include<stdio.h>



#include "SqQueue.h"
#include "LinkQueue.h"


// SqQueue 
void test01() {
    SqQueue Q;
    InitQueue(&Q);
    if(IsEmpty(Q)) {
        printf("empty.\n");
    }
    int elem = 10;
    if(EnQueue(&Q, elem)) {
        printf("en: %d\n", elem);
    }
    if(IsEmpty(Q)) {
        printf("empty.\n");
    }
    if(EnQueue(&Q, 12)) {
        printf("en: %d\n", 12);
    }
    if(DeQueue(&Q, &elem)) {
        printf("de: %d\n", elem);
    }
    printf("len:  %d\n", QueueLen(Q));
}
// Link
void test02() {
    LinkQueue Q;
    LInitQueue(&Q);
    if(LIsEmpty(Q)) {
        printf("empty.\n");
    }
    int elem = 10;
    if(LEnQueue(&Q, elem)) {
        printf("en: %d\n", elem);
    }
    if(LIsEmpty(Q)) {
        printf("empty.\n");
    }
    if(LEnQueue(&Q, 12)) {
        printf("en: %d\n", 12);
    }
    if(LDeQueue(&Q, &elem)) {
        printf("de: %d\n", elem);
    }
    printf("len:  %d\n", Q.front->date);

}

int main() {
    test01();
    test02();





    return 0;
}