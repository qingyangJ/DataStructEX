#pragma once

#define ElemType int

// 结点
typedef struct DNode
{
    struct DNode *prior, *next;
    ElemType data;
}DNode, *DLinkList;

// 建立链表--1.头插法建立
DLinkList DListHeadInsert(DLinkList* const L);

// 2.尾插法建立链表
DLinkList DListTailInsert(DLinkList* const L);

// 按序号查找结点值
// 传入参数：链表指针，位序
// 返回值：指向该结点的指针
DNode* DGetElem(DLinkList* const L, int pos);
// 按值查找
// 传入参数：链表指针，位序
// 返回值：指向该结点的指针
DNode* DGetValue(DLinkList* const L, ElemType elem);
// 插入到链表中第pos个位置上
// 按值查找
// 传入参数：链表指针，位序,值
// 返回值：链表头指针
DLinkList DInsertElem(DLinkList* const L, int pos, ElemType elem);
// 删除结点操作
// 删除第i个结点。
// 传入参数：链表指针，位序。
// 返回值：链表头指针。
DLinkList DDelElem(DLinkList* const L, int pos);
// 求表长
int DListLength(DLinkList* const L);
// 遍历链表
void DTraverList(DLinkList* const L);
