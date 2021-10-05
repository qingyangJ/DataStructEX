#pragma once
#define ElemType int
#define MAX_SIZE 100
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct {
    /* data */
    ElemType *data; 
    int front, rear;
    int len;
}SqQueue;


// initial
void InitQueue(SqQueue* const Q);
// empty?
BOOL IsEmpty(SqQueue Q);
// in
BOOL EnQueue(SqQueue* const Q, ElemType elem);
// out
BOOL DeQueue(SqQueue* const Q, ElemType* const elem);
// len
int QueueLen(SqQueue Q);