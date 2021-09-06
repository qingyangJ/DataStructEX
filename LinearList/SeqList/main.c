#include "SeqList.h"
#include<stdio.h>

// 基本操作
void test0() {
    SeqList seqL;
    
    InitList(&seqL);
    InsertElem(&seqL, 1, 10);
    InsertElem(&seqL, 2, 50);
    TraverseList(&seqL);
    ElemType value=0;
    ElemType pos = 1;
    DeleteList(&seqL, pos, &value);
    printf("The delete pos:%d---value:%d\n", pos, value);
    TraverseList(&seqL);
    ListLength(&seqL);
    printf("GetElem:%d\n",GetElem(&seqL, pos));
    printf("The value:%d---pos:%d\n", 50, LocateElem(&seqL, 50));
    printf("The value:%d---pos:%d\n", 2, LocateElem(&seqL, 2));
    if(ListIsEmpty(&seqL)) printf("List is Empty--!\n");
    DestroyList(&seqL);
    if(ListIsEmpty(&seqL)) printf("Destroyed List is Empty--!\n");
}


// DelMin
void test1() {
    SeqList s1;
    InitList(&s1);
    int n = 10;
    for(int i =1; i<n; i++) {
        InsertElem(&s1, i, i*6);
    }
    InsertElem(&s1, 6, 1);
    if(ListIsEmpty(&s1)) {
        printf("List is empty.\n");
    }
    TraverseList(&s1);
    printf("Min:%d\n", DelMin(&s1));
    TraverseList(&s1);
}


int main(int argc, char *agrv[]) {
   
    test1();
    return 0;
}