#include "SeqList.h"
#include<stdio.h>

int main(int argc, char *agrv[]) {
    SeqList seqL;
    
    if(!InitList(&seqL)) return -1;
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
    if(!ListEmpty(&seqL)) printf("List is Empty--!\n");
    DestroyList(&seqL);
    if(!ListEmpty(&seqL)) printf("Destroyed List is Empty--!\n");

    return 0;
}