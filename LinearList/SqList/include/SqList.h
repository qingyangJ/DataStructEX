#pragma once
#define BOOL int
#define TRUE 1
#define FALSE 0
#define ElemType int
#define MAXSIZE 100


//  create static SqList
typedef struct SqList
{
    /* data */
    ElemType data[MAXSIZE];
    int length;
}SqList;

//  initial
BOOL InitList(SqList* const L);
//  insert SqList
void InsertElem(SqList* const L, int pos, ElemType elem);
//  按位序删除,将被删除的元素值赋给elem
void DeleteList(SqList* const L, int pos, ElemType* const elem);
//  求表长
int ListLength(const SqList* const L);
//  按值查找,并返回其位序
int LocateElem(const SqList* const L, ElemType elem);
//  按位查找，并返回其值
int GetElem(const SqList* const L, int pos);
//  判空
BOOL ListEmpty(const SqList* const L);
//  销毁线性表
void DestroyList(SqList* L);



//  遍历
void TraverseList(SqList* const L);




//  delete min,return value
ElemType DelMin(SqList* const L);