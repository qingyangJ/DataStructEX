#pragma once
#define ElemType char
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct SNode {
    /* data */
    ElemType data;
    struct SNode *next;
}SNode;

typedef struct Stack {
    /* data */
    SNode *base;
    SNode *top;
    int height; // Õ»¸ß
}Stack;

// INITIAL
BOOL InitStack(Stack* const S);
// PUSH
BOOL SPush(Stack* const S, ElemType elem);
// POP
BOOL SPop(Stack* const S, ElemType* const elem);
// EMPTY?
BOOL IsEmpty(Stack* const S);

