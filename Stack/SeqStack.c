#include<stdlib.h>
#include<stdio.h>

#include "SeqStack.h"



// initailize
void Initailize(SeqStack* const S) {
    S->data = (ElemType*)malloc(sizeof(ElemType)*MAX_SIZE);
    S->top = -1; // 初始化栈顶指针
}
// 判空
BOOL StackIsEmpty(SeqStack S) {
    if(S.top == -1) {
        return TRUE;
    } else {
        return FALSE;
    }
}
// PUSH
BOOL Push(SeqStack* const S, ElemType elem) {
    // 判断是否满了,满了则重新分配
    if(S->top == MAX_SIZE-1) {
        printf("NO SAPCE. RESIZEING.\n");
        ElemType *temp = (ElemType*)malloc(sizeof(ElemType)*(MAX_SIZE+100));
        // 搬数据
        for(int i = 0; i<MAX_SIZE; i++) {
            temp[i] = S->data[i];
        }
        // 释放原空间
        free(S->data);
        S->data = temp;
    }
    // push
    S->data[++(S->top)] = elem;
    return TRUE;
}
// POP
BOOL Pop(SeqStack* const S, ElemType* const elem) {
    // 判空
    if(S->top == -1) {
        printf("null \n");
        return FALSE;
    }
    *elem = S->data[(S->top)--];
    return TRUE;
}
// GetTop
BOOL GetTop(SeqStack S, ElemType* const elem) {
    if(S.top == -1) {
        return FALSE;
    }
    *elem = S.data[S.top];
    return TRUE;
}