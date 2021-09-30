#include"CLinkList.h"

#include "stdio.h"
#include "stdlib.h"

// 1.β�巨��������
CLinkList CListTailInsert(CLinkList* const L) {
    int data = 0;
    CNode *node, *tail;
    // ����ͷ�ڵ�
    *L = (CLinkList)malloc(sizeof(CNode));
    if(!*L) exit(-1);
    // ͷ�ڵ���������������
    (*L)->data = 0;
    (*L)->next = *L;
    (*L)->prior = *L;
    tail = *L;
    // ����Ҫ�����ֵ
    while (scanf("%d",&data) != EOF) {
        /* code */
        node = (CNode*)malloc(sizeof(CNode)); // �����½��
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

// ����Ų��ҽ��ֵ
// �������������ָ�룬λ��
// ����ֵ��ָ��ý���ָ��
CNode* CGetElem(CLinkList* const L, int pos) {
    // �пգ����ؿ�
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

// ��ֵ����
// �������������ָ�룬λ��
// ����ֵ��ָ��ý���ָ��
CNode* CGetValue(CLinkList* const L, ElemType elem) {
    // �пգ����ؿ�
    if(*L == NULL) exit(-1);
    CNode *p = (*L)->next;
    while (p != *L && p->data != elem)
    {
        p = p->next;
    }
    return p;
}

// ���뵽�����е�pos��λ����
// ��ֵ����
// �������������ָ�룬λ��,ֵ
// ����ֵ������ͷָ��
CLinkList CInsertElem(CLinkList* const L, int pos, ElemType elem) {
    // �ж���������Ժ�λ������ԡ�
    if(*L == NULL || pos<1) {
        exit(-1);
    }
    // ����--ǰ��
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

// ɾ��������
// ɾ����i����㡣
// �������������ָ�룬λ��
// ����ֵ������ͷָ�롣
CLinkList CDelElem(CLinkList* const L, int pos) {
    // �ж���������Ժ�λ������ԡ�
    if(*L == NULL || pos<1) {
        exit(-1);
    }
    // ɾ����ǰ���
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
// ���
int CListLength(CLinkList* const L) {
    return (*L)->data;
}
// ��������
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


