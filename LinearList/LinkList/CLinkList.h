#pragma once

#define ElemType int

// 结点
typedef struct CNode
{
    struct CNode *prior, *next;
    ElemType data;
}CNode, *CLinkList;

// 尾插法建立链表
CLinkList CListTailInsert(CLinkList* const L);

// 按序号查找结点值
// 传入参数：链表指针，位序
// 返回值：指向该结点的指针
CNode* CGetElem(CLinkList* const L, int pos);
// 按值查找
// 传入参数：链表指针，位序
// 返回值：指向该结点的指针
CNode* CGetValue(CLinkList* const L, ElemType elem);
// 插入到链表中第pos个位置上
// 按值查找
// 传入参数：链表指针，位序,值
// 返回值：链表头指针
CLinkList CInsertElem(CLinkList* const L, int pos, ElemType elem);
// 删除结点操作
// 删除第i个结点。
// 传入参数：链表指针，位序。
// 返回值：链表头指针。
CLinkList CDelElem(CLinkList* const L, int pos);
// 求表长
int CListLength(CLinkList* const L);
// 遍历链表
void CTraverList(CLinkList* const L);
void RCTraverList(CLinkList* const L);

