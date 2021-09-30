#include"CLinkList.h"

#include "stdio.h"
#include "stdlib.h"

// 1.尾插法建立链表
CLinkList CListTailInsert(CLinkList* const L) {
    int data = 0;
    CNode *node, *tail;
    // 创建头节点
    *L = (CLinkList)malloc(sizeof(CNode));
    if(!*L) exit(-1);
    // 头节点数据域存放链表长度
    (*L)->data = 0;
    (*L)->next = *L;
    (*L)->prior = *L;
    tail = *L;
    // 输入要插入的值
    while (scanf("%d",&data) != EOF) {
        /* code */
        node = (CNode*)malloc(sizeof(CNode)); // 创建新结点
        node->data = data;
        node->prior = tail;
        tail->next = node;
        tail = node;
        (*L)->data++;
    }
    tail->next = *L;
    (*L)->prior = tail;
    return *L;
}

// 按序号查找结点值
// 传入参数：链表指针，位序
// 返回值：指向该结点的指针
CNode* CGetElem(CLinkList* const L, int pos) {
    // 判空，返回空
    if(*L == NULL) exit(-1);
    CNode *p = (*L);
    if(p->next == *L) {
        printf("List is empty.\n");
        return NULL;
    }
    if(pos<1) return NULL;
    while (pos--)
    {
        if(p->next == *L) {
            return NULL;
        }
        p = p->next;
    }
    return p;
}

// 按值查找
// 传入参数：链表指针，位序
// 返回值：指向该结点的指针
CNode* CGetValue(CLinkList* const L, ElemType elem) {
    // 判空，返回空
    if(*L == NULL) exit(-1);
    CNode *p = (*L)->next;
    while (p != *L && p->data != elem)
    {
        p = p->next;
    }
    return p;
}

// 插入到链表中第pos个位置上
// 按值查找
// 传入参数：链表指针，位序,值
// 返回值：链表头指针
CLinkList CInsertElem(CLinkList* const L, int pos, ElemType elem) {
    // 判断链表合理性和位序合理性。
    if(*L == NULL || pos<1) {
        exit(-1);
    }
    // 插入--前插
    CNode *p = *L;
    int i = pos;
    while (i--)
    {
        if(p->next == *L) {
            return NULL;
        }
        p = p->next;
    }
    // insert
    CNode *temp = (CNode*)malloc(sizeof(CNode));
    temp->data = elem;

    temp->next = p;
    temp->prior = p->prior;
    p->prior->next = temp;
    p->prior = temp;
    (*L)->data++;
    return *L;
}

// 删除结点操作
// 删除第i个结点。
// 传入参数：链表指针，位序。
// 返回值：链表头指针。
CLinkList CDelElem(CLinkList* const L, int pos) {
    // 判断链表合理性和位序合理性。
    if(*L == NULL || pos<1) {
        exit(-1);
    }
    // 删除当前结点
    CNode *q = *L;
    while (pos--)
    {
        if(q->next == *L) {
            return NULL;
        }
        q = q->next;
    }
    // delete
    q->prior->next = q->next;
    q->next->prior = q->prior;
    free(q);
    (*L)->data--;
    return *L;
}
// 求表长
int CListLength(CLinkList* const L) {
    return (*L)->data;
}
// 遍历链表
void CTraverList(CLinkList* const L) {
    CNode *p = (*L)->next;
    while (p != *L)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}
void RCTraverList(CLinkList* const L) {
    CNode *p = (*L)->prior;
    while (p != *L)
    {
        printf("%d  ", p->data);
        p = p->prior;
    }
    printf("\n");
}


