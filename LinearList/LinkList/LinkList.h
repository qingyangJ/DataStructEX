#pragma once

#define ElemType int

// 定义单链表结点类型
typedef struct LNode
{
    /* data */
    ElemType data; // 数据域
    struct LNode *next; // 指针域
}LNode, *LinkList;

// 建立链表--1.头插法建立
LinkList ListHeadInsert(LinkList* const L);

// 2.尾插法建立链表
LinkList ListTailInsert(LinkList* const L);

// 按序号查找结点值
// 传入参数：链表指针，位序
// 返回值：指向该结点的指针
LNode* GetElem(LinkList* const L, int pos);
// 按值查找
// 传入参数：链表指针，位序
// 返回值：指向该结点的指针
LNode* GetValue(LinkList* const L, ElemType elem);
// 插入到链表中第pos个位置上
// 按值查找
// 传入参数：链表指针，位序,值
// 返回值：链表头指针
LinkList InsertElem(LinkList* const L, int pos, ElemType elem);
// 删除结点操作
// 删除第i个结点。
// 传入参数：链表指针，位序。
// 返回值：链表头指针。
LinkList DelElem(LinkList* const L, int pos);
// 求表长
int ListLength(LinkList* const L);
// 遍历链表
void TraverList(LinkList* const L);
