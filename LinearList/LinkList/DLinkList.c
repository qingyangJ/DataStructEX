#include"DLinkList.h"

#include "stdio.h"
#include "stdlib.h"

// 建立链表--1.头插法建立
DLinkList DListHeadInsert(DLinkList* const L) {
    int data = 0;
    DNode *node = NULL;
    // 创建头节点
    *L = (DLinkList)malloc(sizeof(DNode));
    if(!*L) exit(-1);
    // 头节点数据域存放链表长度
    (*L)->data = 0;
    (*L)->next = NULL;
    (*L)->prior = NULL;
    // 输入要插入的值
    while (scanf("%d",&data) != EOF) {
        /* code */
        node = (DNode*)malloc(sizeof(DNode)); // 创建新结点
        node->next = (*L)->next;
        (*L)->next->prior = node;
        node->prior = (*L);
        (*L)->next = node;
        (*L)->data++;
    }
    return *L;
}

// 2.尾插法建立链表
DLinkList DListTailInsert(DLinkList* const L) {
    int data = 0;
    DNode *node, *tail = NULL;

    // 创建头节点
    *L = (DLinkList)malloc(sizeof(DNode));
    if(!*L) exit(-1);
    // 头节点数据域存放链表长度
    (*L)->data = 0;
    (*L)->next = NULL;
    (*L)->prior = NULL;
    tail = *L;
    // 输入要插入的值
    while (scanf("%d",&data) != EOF) {
        /* code */
        node = (DNode*)malloc(sizeof(DNode)); // 创建新结点
        node->data = data;
        node->prior = tail;
        tail->next = node;
        tail = node;
        (*L)->data++;
    }
    tail->next = NULL;
    return *L;

}

// 按序号查找结点值
// 传入参数：链表指针，位序
// 返回值：指向该结点的指针
DNode* DGetElem(DLinkList* const L, int pos) {
    // 判空，返回空
    if(*L == NULL) exit(1);
    DNode *p = (*L)->next;
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
DNode* DGetValue(DLinkList* const L, ElemType elem) {
    // 判空，返回空
    if(*L == NULL) exit(-1);
    DNode *p = (*L)->next;
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
DLinkList DInsertElem(DLinkList* const L, int pos, ElemType elem) {
    // 判断链表合理性和位序合理性。
    if(*L == NULL || pos<1) {
        exit(-1);
    }
    // 插入--前插
 
    DNode *p = *L;
    while (pos--)
    {
        if(p == NULL) {
            return NULL;
        }
        p = p->next;
    }
    // insert
    DNode *temp = (DNode*)malloc(sizeof(DNode));
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
DLinkList DDelElem(DLinkList* const L, int pos) {
    // 判断链表合理性和位序合理性。
    if(*L == NULL || pos<1) {
        exit(-1);
    }
    // 删除当前结点
    DNode *q = *L;
    while (pos--)
    {
        if(q == NULL) {
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
int DListLength(DLinkList* const L) {
    return (*L)->data;
}
// 遍历链表
void DTraverList(DLinkList* const L) {
    DNode *p = (*L)->next;
    while (p)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}


