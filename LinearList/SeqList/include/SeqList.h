#pragma once
#define BOOL int
#define TRUE 1
#define FALSE 0
#define ElemType int
#define MAXSIZE 100


//  create dynamic seqList
typedef struct SeqList
{
    /* data */
    ElemType *data;
    int MaxSize, length; // 当前分配的存储容量和已有线性表长度
}SeqList;

//  initial
void InitList(SeqList* const L);
//  insert seqList
void InsertElem(SeqList* const L, int pos, ElemType elem);

//  按位序删除,将被删除的元素值赋给elem
void DeleteList(SeqList* const L, int pos, ElemType* const elem);
//  求表长
int ListLength(const SeqList* const L);
//  按值查找,并返回其位序
int LocateElem(const SeqList* const L, ElemType elem);
//  按位查找，并返回其值
int GetElem(const SeqList* const L, int pos);
//  判空
BOOL ListIsEmpty(const SeqList* const L);
//  销毁线性表
void DestroyList(SeqList* L);

//  遍历
void TraverseList(SeqList* const L);

/*  从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值，
    空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出。
*/
ElemType DelMin(SeqList* const L);