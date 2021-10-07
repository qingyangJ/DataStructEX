#include "Stack.h"

#include<stdlib.h>
#include<stdio.h>


// INITIAL
BOOL InitStack(Stack* const S) {
    S->base = NULL;
    S->top = NULL;
    S->height = 0;
}
// PUSH
BOOL SPush(Stack* const S, ElemType elem) {
    if(S->top = NULL) {
        S->top = (SNode*)malloc(sizeof(SNode));
        S->top->data = elem;
        S->top->next = NULL;
        S->base = S->top;
    } else {
        SNode *temp = (SNode*)malloc(sizeof(SNode));
        temp->data = elem;
        temp->next = S->top;
        S->top = temp;
    }
    S->height++;
}
// POP
BOOL SPop(Stack* const S, ElemType* const elem) {
    // empty?
    if(S->top == NULL) {
        return FALSE;
    }
    *elem = S->top->data;
    SNode *q = S->top;
    S->top = q->next;
    free(q);
    q = NULL;
    S->height--;
}
// EMPTY?
BOOL IsEmpty(Stack* const S) {
    if(S->top == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}