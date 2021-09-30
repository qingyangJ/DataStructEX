#pragma once

#define ElemType int

// ���
typedef struct CNode
{
    struct CNode *prior, *next;
    ElemType data;
}CNode, *CLinkList;

// β�巨��������
CLinkList CListTailInsert(CLinkList* const L);

// ����Ų��ҽ��ֵ
// �������������ָ�룬λ��
// ����ֵ��ָ��ý���ָ��
CNode* CGetElem(CLinkList* const L, int pos);
// ��ֵ����
// �������������ָ�룬λ��
// ����ֵ��ָ��ý���ָ��
CNode* CGetValue(CLinkList* const L, ElemType elem);
// ���뵽�����е�pos��λ����
// ��ֵ����
// �������������ָ�룬λ��,ֵ
// ����ֵ������ͷָ��
CLinkList CInsertElem(CLinkList* const L, int pos, ElemType elem);
// ɾ��������
// ɾ����i����㡣
// �������������ָ�룬λ��
// ����ֵ������ͷָ�롣
CLinkList CDelElem(CLinkList* const L, int pos);
// ���
int CListLength(CLinkList* const L);
// ��������
void CTraverList(CLinkList* const L);
void RCTraverList(CLinkList* const L);

