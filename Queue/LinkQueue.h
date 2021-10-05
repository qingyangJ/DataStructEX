#pragma once
#define ElemType int
#define MAX_SIZE 100
#define BOOL int
#define TRUE 1
#define FALSE 0


typedef struct QNode{
    /* data */
    ElemType date;
    struct QNode *next;
}QNode;

typedef struct {
    /* data */
    QNode *front, *rear;
}LinkQueue;

// initail
void LInitQueue(LinkQueue* const Q);
// null?
BOOL LIsEmpty(LinkQueue Q);
// en
BOOL LEnQueue(LinkQueue* const Q, ElemType elem);
// out
BOOL LDeQueue(LinkQueue* const Q, ElemType *elem);


