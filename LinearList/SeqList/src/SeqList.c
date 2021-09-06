#include "SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//  initial
void InitList(SeqList* const L) {
    L->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    if(!L->data) {
        printf("初始化线性表失败.\n");
        return;
    }
    L->length = 0;
    L->MaxSize = MAXSIZE;
}
//  insert seqList
void InsertElem(SeqList* const L, int pos, ElemType elem) {
    // 判断pos是否合法
    if(pos<1 || pos>L->length+1) {
        printf("SeqInsertElem's pos is illegal!\n");
        return;
    } 
    // 判断空间是否足够
    if(L->length >= MAXSIZE) {
        ElemType *p = (ElemType*)realloc(L->data, (L->MaxSize+1)*sizeof(ElemType));
        if(!p) {
            printf("The space is insufficient!\n");
            return;
        }
        L->data = p;
        L->MaxSize++;
    }
    // 插入
    for(int j = L->length; j>=pos; j--) {
        L->data[j] = L->data[j-1];
    }
    L->data[pos-1] = elem;
    L->length++;
}

//  删除线性表元素
void DeleteList(SeqList* const L, int pos, ElemType* const elem) {
     //  检查位序是否合法
    if(pos<1 || pos>L->length+1) {
        printf("SqInsertElem's pos is illegal!\n");
        return;
    }
    //  delete
    *elem = L->data[pos-1];
    for(int i = pos; i<=L->length;i++) {
        L->data[i-1] = L->data[i];
    }
    L->length--;
}
//  返回线性表的长度
int ListLength(const SeqList* const L) {
    printf("The length of SeqList is :%d\n", L->length);
    return L->length;
}
//  查找元素，返回其位序
int LocateElem(const SeqList* const L, ElemType elem) {
    for(int i = 0; i<L->length;i++) {
        if(L->data[i] == elem) {
            return i+1;
        }
    }
    printf("There is No element in SeqList --\n");
    return -1;
}
//  获取指定位序上的元素
int GetElem(const SeqList* const L, int pos) {
    //  检查pos合法性
    if(pos<1 || pos>L->length+1) {
        printf("SqInsertElem's pos is illegal!\n");
        return -1;
    }
    return L->data[pos-1];
}

//  判断线性表是否为空
BOOL ListIsEmpty(const SeqList* const L) {
    if(L->length<1) {
        return TRUE;
    }
    return FALSE;
}
//  销毁线性表--记得释放指针
void DestroyList(SeqList* L) {
    L->length = 0;
    L->MaxSize = 0;
    free(L->data);
    L->data = NULL;
}
//  遍历线性表
void TraverseList(SeqList* const L) {
    printf("SeqList: ");
    for(int i = 1; i<L->length+1; i++) {
        printf("-->%d",L->data[i-1]);
    }
    printf("\n");
}


ElemType DelMin(SeqList* const L) {
    // 判空
    if(L->length < 1) {
        printf("DeMin() error! List is empty.\n");
        exit(-1);
    }
    int min = L->data[0];
    int index = 0;
    for(int i = 1; i<L->length; i++) {
        if(min > L->data[i]) {
            min = L->data[i];
            index = i;
        }
    }
    L->data[index] = L->data[L->length-1];
    return min;
}