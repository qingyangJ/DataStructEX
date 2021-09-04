#include "SqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//  initial
BOOL InitList(SqList* const L) {
    //  初始化为0
    memset(L->data, 0, sizeof(ElemType)*MAXSIZE);
    L->length = 0;
    return TRUE;
}

//  insert SqList
void InsertElem(SqList* const L, int pos, ElemType elem) {
    //  判断 pos 是否合法
    if(pos<1 || pos>L->length+1) {
        printf("SqInsertElem's pos is illegal!\n");
        return;
    }
    //  判断是否有空间插入
    if(L->length >= MAXSIZE) {
        printf("The space is insufficient!\n");
        return;
    } 
    //  插入
    for(int i = L->length; i>=pos; i--) {
        L->data[i] = L->data[i-1];
    }
    L->data[pos-1] = elem;
    L->length++;
}

//  求表长
int ListLength(const SqList* const L) {
    printf("The length of SqList is :%d\n", L->length);
    return L->length;
}

//  删除
void DeleteList(SqList* const L, int pos, ElemType* const elem) {
     //  判断 pos 是否合法
    if(pos<1 || pos>L->length+1) {
        printf("SqInsertElem's pos is illegal!\n");
        return;
    }
    //  判断是否有空间插入
    if(L->length >= MAXSIZE) {
        printf("The space is insufficient!\n");
        return;
    } 
    //  delete
    *elem = L->data[pos-1];
    for(int i = pos; i<=L->length;i++) {
        L->data[i-1] = L->data[i];
    }
    L->length--;
}

//  按值查找,并返回其位序
int LocateElem(const SqList* const L, ElemType elem) {
    for(int i = 0; i<L->length;i++) {
        if(L->data[i] == elem) {
            return i+1;
        }
    }
    printf("There is No element in SqList --\n");
    return -1;
}
//  按位查找，并返回其值
int GetElem(const SqList* const L, int pos) {
    //  判断 pos 是否合法
    if(pos<1 || pos>L->length+1) {
        printf("SqInsertElem's pos is illegal!\n");
        return -1;
    }
    return L->data[pos-1];
}

//  判空
BOOL ListEmpty(const SqList* const L) {
    if(L->length<1) {
        return FALSE;
    }
    return TRUE;
}
//  销毁线性表
void DestroyList(SqList* L) {
    L->length = 0;
    L=NULL;
}
//  遍历
void TraverseList(SqList* const L) {
    printf("SqList: ");
    for(int i = 1; i<L->length+1; i++) {
        printf("-->%d",L->data[i-1]);
    }
    printf("\n");
}
//  delete min,return value
ElemType DelMin(SqList* const L) {

}