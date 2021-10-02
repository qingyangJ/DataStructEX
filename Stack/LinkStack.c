#include<stdlib.h>
#include<stdio.h>

#include "LinkStack.h"

// initailize
void LInitailize(Stack* const S) {
    S->top = NULL;
    S->bottom = NULL;
    S->height = 0;
}

// еп©у
BOOL LStackIsEmpty(Stack S) {
    if(S.height == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// PUSH
BOOL LPush(Stack* const S, ElemType elem) {
    // г╟╡Е
    SNode *temp = (SNode*)malloc(sizeof(SNode));
    if(!temp) return FALSE;
    if(S->top == NULL) {
        temp->data = elem;
        temp->next = NULL;
        S->top = temp;
        S->bottom = temp;
        S->height++;
    } else {
        temp->data = elem;
        temp->next = S->top;
        S->top = temp;
        S->height++;
    }
    return TRUE;
}
// POP
BOOL LPop(Stack* const S, ElemType* const elem){
    if(S->top == NULL) {
        printf("empty.\n");
        return FALSE;
    }
    *elem = S->top->data;
    SNode *q = S->top;
    S->top = q->next;
    free(q);
    S->height--;
    return TRUE;
}
// GetTop
BOOL LGetTop(Stack S, ElemType* const elem) {
    *elem = S.top->data;
    return TRUE;
}