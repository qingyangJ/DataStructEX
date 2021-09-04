#include "SqList.h"
#include<stdio.h>

int main(int argc, char *agrv[]) {
    SqList sqL;
    
    if(!InitList(&sqL)) return -1;
    InsertElem(&sqL, 1, 1);
    InsertElem(&sqL, 2, 2);
    TraverseList(&sqL);
    ElemType value=0;
    ElemType pos = 1;
    DeleteList(&sqL, pos, &value);
    printf("The delete pos:%d---value:%d\n", pos, value);
    TraverseList(&sqL);
    ListLength(&sqL);
    printf("GetElem:%d\n",GetElem(&sqL, pos));
    printf("The value:%d---pos:%d\n", 1, LocateElem(&sqL, 1));
    printf("The value:%d---pos:%d\n", 2, LocateElem(&sqL, 2));
    if(!ListEmpty(&sqL)) printf("List is Empty--!\n");
    DestroyList(&sqL);
    if(!ListEmpty(&sqL)) printf("Destroyed List is Empty--!\n");



    return 0;
}