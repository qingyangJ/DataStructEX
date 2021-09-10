#pragma once
#define BOOL int
#define TRUE 1
#define FALSE 0
#define ElemType int
#define MAXSIZE 100
#define INT_MAX 0X7fffffff


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
/*  8.
    已知在一维数组A[m+n]中依次存放两个线性表(a1...am)和(b1...bn)，
    编写函数，将数组中两个顺序表的位置互换，即(b1..bn)放在(a1...am)之前。
    先将整体逆置，存储位置确定，再逐步逆转
*/
void ReverseArr(ElemType A[], int left, int right, int arrsize);
void Exchange(ElemType A[], int m, int n, int arrsize);
/*  9.
    线性表(a1..an)中的元素递增有序且顺序存储于计算机内。
    设计一个算法，用最少时间在表中查找数值为x的元素，
    若找到，则与其后继元素位置相交换，若找不到，则将其插入表中，
    并保持表中元素递增。
    二分查找，后移插入
*/
void SearchMin(SeqList* const L, ElemType elem);
/* 10.
    将n个（n>1）个整数存到一维数组R中，将R中的序列循环左移P个位置(0<p<n)
    个位置。
    先将前p个元素逆置，再将后p个元素逆置，再整体逆置-同8。
*/
void CircleExchange(ElemType A[], int left, int right,  int arrsize, int p);
/*  11.一个长度为L(L>=1)的升序序列S，处在第[L/2]（向上取整）个位置的数称为S的中位数。
    两个序列的中位数是含他们所有元素的升序序列的中位数。现在有登场的A,B两个升序序列。
    求其中位数。要求T(O)，S(O)最优。
    设A的中位数为a,B的为b,当a>b时，中位数所在区间[b,a],else所在区间[a,b]
*/
void MidNum(SeqList* const A, SeqList* const B, ElemType* midnum);
/*  12. 已知一个整数序列A(a0...an-1),(0<=ai<n)(0<=i<n)。若存在ap1=ap2=...apm=x
且m>n/2,(0<=pk<n,1<=k<=m)，则称 x 为A的主元素。假设A中的n个元素保存在一个一维数组中，
找出A的主元素，若存在主元素，则输出该元素，否则输出-1.
    先找出现次数最多的数，再判断是否为主元素。
*/
ElemType SearchMainElem(SeqList* const A);
/*  13.一个含n（n>=1）个整数的数组，找出数组中未出现的最小正整数。
    空间换时间
*/
ElemType SearchNMin(SeqList* const A);
/*  14.定义一个三元组(a,b,c均为正数)的距离D = |a-b|+|b-c|+|c-a|。
    给定一个非空整数集合S1,S2,S3，按照升序分别存储再三个数组中。计算出
    所有可能的三元组(a,b,c)(a∈S1，b∈S2,c∈S3)中的最小距离。
*/
BOOL FirstISMin(ElemType a, ElemType b, ElemType c);
int MinD(SeqList* const S1, SeqList* const S2, SeqList* const S3);











