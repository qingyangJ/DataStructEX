#include"LinkList.h"

#include "stdio.h"
#include "stdlib.h"

// 建立链表--1.头插法建立
LinkList ListHeadInsert(LinkList* const L) {
    int data = 0;
    LNode *node;
    // 创建头结点
    *L = (LinkList)malloc(sizeof(LNode));
    if(!*L) exit(-1);
    (*L)->next = NULL;
    // 输入结点的值
    while (scanf("%d",&data) != EOF) {
        /* code */
        node = (LNode*)malloc(sizeof(LNode)); // 创建新结点
        node->data = data;
        node->next = (*L)->next;
        (*L)->next = node;
    }
    return *L;
}
// 2.尾插法建立链表
LinkList ListTailInsert(LinkList* const L) {
    int data = 0;
    LNode *node, *tail;
    // 创建头结点
    *L = (LinkList)malloc(sizeof(LNode));
    if(!*L) exit(-1);
    (*L)->next = NULL;
    tail = *L;
    // 输入结点的值
    while (scanf("%d",&data) != EOF) {
        /* code */
        node = (LNode*)malloc(sizeof(LNode)); // 创建新结点
        node->data = data;
        tail->next = node;
        tail = node;
    }
    tail->next = NULL;
    return *L;
}
// 按序号查找结点值
// 传入参数：链表指针，位序
// 返回值：指向该结点的指针
LNode* GetElem(LinkList* const L, int pos) {
    // 判空，返回空
    if(*L == NULL) exit(1);
    LNode *p = (*L)->next;
    if(p == NULL ) {
        printf("List is empty.\n");
        return NULL;
    }
    if(pos<1) return NULL;
    int i = 1;
    while(i != pos && p != NULL) {
        p = p->next;
        i++;
    }
    return p;
}
// 按值查找
// 传入参数：链表指针，位序
// 返回值：指向该结点的指针
LNode* GetValue(LinkList* const L, ElemType elem) {
    // 判空，返回空
    if(*L == NULL) exit(-1);
    LNode *p = (*L)->next;
    while (p != NULL && p->data != elem)
    {
        p = p->next;
    }
    return p;
}
// 插入到链表中第pos个位置上
// 按值查找
// 传入参数：链表指针，位序,值
// 返回值：链表头指针
LinkList InsertElem(LinkList* const L, int pos, ElemType elem) {
    // 判断链表合理性和位序合理性。
    if(*L == NULL || pos<1) {
        exit(-1);
    }
    // 遍历到第pos-1位置上
    LNode *pre = *L;
    int i = pos-1;
    while (i--)
    {
        if(pre == NULL) {
            return NULL;
        }
        pre = pre->next; 
    }
    // 插入
    LNode *temp = (LNode*)malloc(sizeof(LNode));
    temp->data = elem;
    temp->next = pre->next;
    pre->next = temp;
    return *L;
}
// 删除结点操作
// 删除第i个结点。
// 传入参数：链表指针，位序。
// 返回值：链表头指针。
LinkList DelElem(LinkList* const L, int pos) {
    // 判断链表合理性和位序合理性。
    if(*L == NULL || pos<1) {
        exit(1);
    }
    // 遍历到第pos-1位置上
    LNode *pre = *L;
    LNode *q = NULL;
    int i = pos-1;
    while (i--) {
        if(pre == NULL) {
            return NULL;
        }
        pre = pre->next; 
    }
    q = pre->next;
    pre->next = q->next;
    free(q);
    return *L;
}
// 求表长
int ListLength(LinkList* const L) {
    if(*L == NULL) exit(-1);
    LNode *p = (*L)->next;
    int num = 0;
    while (p) {
        p = p->next;
        num++;
    }
    return num;
}
// 遍历链表
void TraverList(LinkList* const L) {
    LNode *p = (*L)->next;
    while (p)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}