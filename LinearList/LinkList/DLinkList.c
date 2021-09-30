#include"DLinkList.h"

#include "stdio.h"
#include "stdlib.h"

// ��������--1.ͷ�巨����
DLinkList DListHeadInsert(DLinkList* const L) {
    int data = 0;
    DNode *node = NULL;
    // ����ͷ�ڵ�
    *L = (DLinkList)malloc(sizeof(DNode));
    if(!*L) exit(-1);
    // ͷ�ڵ���������������
    (*L)->data = 0;
    (*L)->next = NULL;
    (*L)->prior = NULL;
    // ����Ҫ�����ֵ
    while (scanf("%d",&data) != EOF) {
        /* code */
        node = (DNode*)malloc(sizeof(DNode)); // �����½��
        node->next = (*L)->next;
        (*L)->next->prior = node;
        node->prior = (*L);
        (*L)->next = node;
        (*L)->data++;
    }
    return *L;
}

// 2.β�巨��������
DLinkList DListTailInsert(DLinkList* const L) {
    int data = 0;
    DNode *node, *tail = NULL;

    // ����ͷ�ڵ�
    *L = (DLinkList)malloc(sizeof(DNode));
    if(!*L) exit(-1);
    // ͷ�ڵ���������������
    (*L)->data = 0;
    (*L)->next = NULL;
    (*L)->prior = NULL;
    tail = *L;
    // ����Ҫ�����ֵ
    while (scanf("%d",&data) != EOF) {
        /* code */
        node = (DNode*)malloc(sizeof(DNode)); // �����½��
        node->data = data;
        node->prior = tail;
        tail->next = node;
        tail = node;
        (*L)->data++;
    }
    tail->next = NULL;
    return *L;

}

// ����Ų��ҽ��ֵ
// �������������ָ�룬λ��
// ����ֵ��ָ��ý���ָ��
DNode* DGetElem(DLinkList* const L, int pos) {
    // �пգ����ؿ�
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

// ��ֵ����
// �������������ָ�룬λ��
// ����ֵ��ָ��ý���ָ��
DNode* DGetValue(DLinkList* const L, ElemType elem) {
    // �пգ����ؿ�
    if(*L == NULL) exit(-1);
    DNode *p = (*L)->next;
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
DLinkList DInsertElem(DLinkList* const L, int pos, ElemType elem) {
    // �ж���������Ժ�λ������ԡ�
    if(*L == NULL || pos<1) {
        exit(-1);
    }
    // ����--ǰ��
 
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

// ɾ��������
// ɾ����i����㡣
// �������������ָ�룬λ��
// ����ֵ������ͷָ�롣
DLinkList DDelElem(DLinkList* const L, int pos) {
    // �ж���������Ժ�λ������ԡ�
    if(*L == NULL || pos<1) {
        exit(-1);
    }
    // ɾ����ǰ���
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
// ���
int DListLength(DLinkList* const L) {
    return (*L)->data;
}
// ��������
void DTraverList(DLinkList* const L) {
    DNode *p = (*L)->next;
    while (p)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}


