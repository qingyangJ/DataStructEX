#pragma once

#define ElemType int

// ���嵥����������
typedef struct LNode
{
    /* data */
    ElemType data; // ������
    struct LNode *next; // ָ����
}LNode, *LinkList;

// ��������--1.ͷ�巨����
LinkList ListHeadInsert(LinkList* const L);

// 2.β�巨��������
LinkList ListTailInsert(LinkList* const L);

// ����Ų��ҽ��ֵ
// �������������ָ�룬λ��
// ����ֵ��ָ��ý���ָ��
LNode* GetElem(LinkList* const L, int pos);
// ��ֵ����
// �������������ָ�룬λ��
// ����ֵ��ָ��ý���ָ��
LNode* GetValue(LinkList* const L, ElemType elem);
// ���뵽�����е�pos��λ����
// ��ֵ����
// �������������ָ�룬λ��,ֵ
// ����ֵ������ͷָ��
LinkList InsertElem(LinkList* const L, int pos, ElemType elem);
// ɾ��������
// ɾ����i����㡣
// �������������ָ�룬λ��
// ����ֵ������ͷָ�롣
LinkList DelElem(LinkList* const L, int pos);
// ���
int ListLength(LinkList* const L);
// ��������
void TraverList(LinkList* const L);
