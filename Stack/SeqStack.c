#include<stdlib.h>
#include<stdio.h>

#include "SeqStack.h"



// initailize
void Initailize(SeqStack* const S) {
    S->data = (ElemType*)malloc(sizeof(ElemType)*MAX_SIZE);
    S->top = -1; // ��ʼ��ջ��ָ��
}
// �п�
BOOL StackIsEmpty(SeqStack S) {
    if(S.top == -1) {
        return TRUE;
    } else {
        return FALSE;
    }
}
// PUSH
BOOL Push(SeqStack* const S, ElemType elem) {
    // �ж��Ƿ�����,���������·���
    if(S->top == MAX_SIZE-1) {
        printf("NO SAPCE. RESIZEING.\n");
        ElemType *temp = (ElemType*)malloc(sizeof(ElemType)*(MAX_SIZE+100));
        // ������
        for(int i = 0; i<MAX_SIZE; i++) {
            temp[i] = S->data[i];
        }
        // �ͷ�ԭ�ռ�
        free(S->data);
        S->data = temp;
    }
    // push
    S->data[++(S->top)] = elem;
    return TRUE;
}
// POP
BOOL Pop(SeqStack* const S, ElemType* const elem) {
    // �п�
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