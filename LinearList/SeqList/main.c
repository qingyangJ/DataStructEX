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

// 线性表赋值,循环输入线性表的元素，空格分隔，回车结束输入。
void CreateL(SeqList* const L) {
    if(!L) return;
    printf("Windows enter Ctrl+Z to end the input.\n");
    ElemType elem = 0;
    int pos = 1;
    while (1)
    {
        int ret = scanf("%d", &elem);
        if(ret==0) {
            printf("input error.\n");
            fflush(stdin);
            return;
        }
        if(ret == EOF) {
            break;
        }
        InsertElem(L, pos, elem);
        pos++;
    }
    // 显示创建的线性表
    if(ListIsEmpty(L)) {
        printf("List is empty.\n");
        return;
    }
    printf("Length:%d\n", ListLength(L));
    TraverseList(L);
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
    CreateL(&s1);
    ListIsEmpty(&s1);
}
int main(int argc, char *agrv[]) {
   
    test02();

    return 0;
}