#include"LinkList.h"

#include "stdio.h"
#include "stdlib.h"

// ��������--1.ͷ�巨����
LinkList ListHeadInsert(LinkList* const L) {
    int data = 0;
    LNode *node;
    // ����ͷ���
    *L = (LinkList)malloc(sizeof(LNode));
    if(!*L) exit(-1);
    (*L)->next = NULL;
    // �������ֵ
    while (scanf("%d",&data) != EOF) {
        /* code */
        node = (LNode*)malloc(sizeof(LNode)); // �����½��
        node->data = data;
        node->next = (*L)->next;
        (*L)->next = node;
    }
    return *L;
}
// 2.β�巨��������
LinkList ListTailInsert(LinkList* const L) {
    int data = 0;
    LNode *node, *tail;
    // ����ͷ���
    *L = (LinkList)malloc(sizeof(LNode));
    if(!*L) exit(-1);
    (*L)->next = NULL;
    tail = *L;
    // �������ֵ
    while (scanf("%d",&data) != EOF) {
        /* code */
        node = (LNode*)malloc(sizeof(LNode)); // �����½��
        node->data = data;
        tail->next = node;
        tail = node;
    }
    tail->next = NULL;
    return *L;
}
// ����Ų��ҽ��ֵ
// �������������ָ�룬λ��
// ����ֵ��ָ��ý���ָ��
LNode* GetElem(LinkList* const L, int pos) {
    // �пգ����ؿ�
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
// ��ֵ����
// �������������ָ�룬λ��
// ����ֵ��ָ��ý���ָ��
LNode* GetValue(LinkList* const L, ElemType elem) {
    // �пգ����ؿ�
    if(*L == NULL) exit(-1);
    LNode *p = (*L)->next;
    while (p != NULL && p->data != elem)
    {
        p = p->next;
    }
    return p;
}
// ���뵽�����е�pos��λ����
// ��ֵ����
// �������������ָ�룬λ��,ֵ
// ����ֵ������ͷָ��
LinkList InsertElem(LinkList* const L, int pos, ElemType elem) {
    // �ж���������Ժ�λ������ԡ�
    if(*L == NULL || pos<1) {
        exit(-1);
    }
    // ��������pos-1λ����
    LNode *pre = *L;
    int i = pos-1;
    while (i--)
    {
        if(pre == NULL) {
            return NULL;
        }
        pre = pre->next; 
    }
    // ����
    LNode *temp = (LNode*)malloc(sizeof(LNode));
    temp->data = elem;
    temp->next = pre->next;
    pre->next = temp;
    return *L;
}
// ɾ��������
// ɾ����i����㡣
// �������������ָ�룬λ��
// ����ֵ������ͷָ�롣
LinkList DelElem(LinkList* const L, int pos) {
    // �ж���������Ժ�λ������ԡ�
    if(*L == NULL || pos<1) {
        exit(1);
    }
    // ��������pos-1λ����
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
// ���
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
// ��������
void TraverList(LinkList* const L) {
    LNode *p = (*L)->next;
    while (p)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}