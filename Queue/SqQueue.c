#include<stdlib.h>
#include "SqQueue.h"



// initial
void InitQueue(SqQueue* const Q) {
    Q->data = (ElemType*)malloc(sizeof(ElemType)*MAX_SIZE);
    Q->front = 0;
    Q->rear = 0;
    Q->len = 0;
}
// empty?
BOOL IsEmpty(SqQueue Q) {
    if(Q.front == Q.rear) {
        return TRUE;
    }
    return FALSE;
}
// in
BOOL EnQueue(SqQueue* const Q, ElemType elem) {
    // full?
    if(((Q->rear)+1)%MAX_SIZE == Q->front) {
        return FALSE;
    }
    Q->data[Q->rear] = elem;
    Q->rear = ((Q->rear)+1)%MAX_SIZE;
    Q->len++;
    return TRUE;
}
// out
BOOL DeQueue(SqQueue* const Q, ElemType* const elem) {
    // null?
    if(Q->front == Q->rear) {
        return FALSE;
    }
    *elem = Q->data[Q->front];
    Q->front = ((Q->front)+1)%MAX_SIZE;
    Q->len--;
    return TRUE;
}
// len
int QueueLen(SqQueue Q) {
    int len = (Q.rear-Q.front+MAX_SIZE)%MAX_SIZE;
    return len;
}