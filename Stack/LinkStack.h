#pragma once
#define ElemType int
#define MAX_SIZE 1
#define BOOL int
#define TRUE 1
#define FALSE 0



// ˳��洢����, ����ͷ�ڵ��
typedef struct SNode{
    /* data */
    ElemType data;
    struct SNode *next; 
} SNode;

typedef struct Stack
{
    /* data */
    SNode *top;        /* ջ��ָ�� */
    SNode *bottom;    /* ջ��ָ�� */
    int height;           /* ջ�ĸ߶� */
}Stack;

// initailize
void LInitailize(Stack* const S);
// �п�
BOOL LStackIsEmpty(Stack S);
// PUSH
BOOL LPush(Stack* const S, ElemType elem);
// POP
BOOL LPop(Stack* const S, ElemType* const elem);
// GetTop
BOOL LGetTop(Stack S, ElemType* const elem);

