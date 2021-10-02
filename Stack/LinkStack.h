#pragma once
#define ElemType int
#define MAX_SIZE 1
#define BOOL int
#define TRUE 1
#define FALSE 0



// 顺序存储类型, 不带头节点的
typedef struct SNode{
    /* data */
    ElemType data;
    struct SNode *next; 
} SNode;

typedef struct Stack
{
    /* data */
    SNode *top;        /* 栈顶指针 */
    SNode *bottom;    /* 栈底指针 */
    int height;           /* 栈的高度 */
}Stack;

// initailize
void LInitailize(Stack* const S);
// 判空
BOOL LStackIsEmpty(Stack S);
// PUSH
BOOL LPush(Stack* const S, ElemType elem);
// POP
BOOL LPop(Stack* const S, ElemType* const elem);
// GetTop
BOOL LGetTop(Stack S, ElemType* const elem);

