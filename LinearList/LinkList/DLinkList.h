#pragma once

#define ElemType int

// ���
typedef struct DNode
{
    struct DNode *prior, *next;
    ElemType data;
}DNode, *DLinkList;

// ��������--1.ͷ�巨����
DLinkList DListHeadInsert(DLinkList* const L);

// 2.β�巨��������
DLinkList DListTailInsert(DLinkList* const L);

// ����Ų��ҽ��ֵ
// �������������ָ�룬λ��
// ����ֵ��ָ��ý���ָ��
DNode* DGetElem(DLinkList* const L, int pos);
// ��ֵ����
// �������������ָ�룬λ��
// ����ֵ��ָ��ý���ָ��
DNode* DGetValue(DLinkList* const L, ElemType elem);
// ���뵽�����е�pos��λ����
// ��ֵ����
// �������������ָ�룬λ��,ֵ
// ����ֵ������ͷָ��
DLinkList DInsertElem(DLinkList* const L, int pos, ElemType elem);
// ɾ��������
// ɾ����i����㡣
// �������������ָ�룬λ��
// ����ֵ������ͷָ�롣
DLinkList DDelElem(DLinkList* const L, int pos);
// ���
int DListLength(DLinkList* const L);
// ��������
void DTraverList(DLinkList* const L);
