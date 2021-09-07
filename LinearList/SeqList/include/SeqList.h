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

// 线性表赋值,循环输入线性表的元素，空格分隔，回车结束输入。
void CreateList(SeqList* const L);
/*  1.
    从顺序表中删除具有最小值的元素（假设唯一,则首次遇到的最小值）
    并由函数返回被删除元素的值，空出的位置由最后一个元素填补，
    若顺序表为空，则显示出错信息并退出。
*/
ElemType DelMin(SeqList* const L); 

/*  2.
    将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
*/
void ListReverse(SeqList* const L);

/*  3.
    长度为n的线性表，删除其中所有值为x的数据元素，时间复杂度O(n),空间复杂度O(1)
*/
void ValueDel(SeqList* const L, ElemType elem);
/*  4.
    从有序顺序表中删除其值在给定值s与t之间(s<t)的所有元素，
    若s或t不合理或顺序表为空，则显示出错信息并退出运行。
*/
void ValueDel4(SeqList* const L, ElemType s, ElemType t);
/*  5.
    从顺序表中删除其值在给定值s与t之间(包含s和t,s<t)的所有元素，
    若s或t不合理或顺序表为空，则显示出错信息并退出运行。
*/
void ValueDel5(SeqList* const L, ElemType s, ElemType t);
/*  6.
    从有序顺序表中删除所有重复的元素
*/
void DelRepeat(SeqList* const L);

/*  7.
    将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
*/
void MergeList(SeqList* const A, SeqList* const B, SeqList* const C);