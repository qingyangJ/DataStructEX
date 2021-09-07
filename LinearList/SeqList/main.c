#include "SeqList.h"
#include<stdio.h>

// 基本操作
void test00() {
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
void test01() {
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
    DestroyList(&s1);
    if(ListIsEmpty(&s1)) {
        printf("List is empty.\n");
    }
}

// Create
void test02() {
    SeqList s1;
    InitList(&s1);
    CreateList(&s1);
    DelMin(&s1);
    TraverseList(&s1);
}
// ListReverse
void test03() {
    SeqList s1;
    InitList(&s1);
    int n = 16;
    for(int i =1; i<n; i++) {
        InsertElem(&s1, i, i);
    }
    TraverseList(&s1);
    ListReverse(&s1);
    TraverseList(&s1);
}
// ValueDel
void test04() {
    SeqList s1;
    InitList(&s1);
    CreateList(&s1);
    // ValueDel(&s1, 5);
    // ValueDel4(&s1, 5 , 9);
    // ValueDel5(&s1, 5 , 9);
    DelRepeat(&s1);
    TraverseList(&s1);
}
// mergeLists
void test05() {
    SeqList A,B,C;
    InitList(&A);
    CreateList(&A);
    InitList(&B);
    CreateList(&B);
    InitList(&C);
    // CreateList(&C);
    MergeList(&A, &B, &C);
    TraverseList(&C);

}
// reverse arr
void test06() {
    int m = 8;
    int n = 6;
    int i = 0;
    int arrsize = 100;
    ElemType A[100] = {0};
    // 初始化 am
    for(i = 0;i<m;i++) {
        A[i] = i;
    }
    // 初始化 bn
    for(;i<m+n;i++) {
        A[i] = 2*n-i;
    }
    printf("Reverse before\n");
    for(i = 0;i<m+n;i++) {
        printf("%d--", A[i]);
    }
    Exchange(A, m, n, arrsize);
    printf("\nReverse after\n");
    for(i = 0;i<m+n;i++) {
        printf("%d--", A[i]);
    }

}
int main(int argc, char *agrv[]) {
   
    test06();
    
    return 0;
}