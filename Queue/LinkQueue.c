#include<stdlib.h>
#include "LinkQueue.h"




// initail
void LInitQueue(LinkQueue* const Q) {
    // Head
    Q->front = (QNode*)malloc(sizeof(QNode));
    Q->rear = Q->front;
    Q->front->next = NULL;
    Q->rear->next = NULL;
    // save length
    Q->front->date = 0;
}
// null?
BOOL LIsEmpty(LinkQueue Q) {
    if(Q.front == Q.rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}
// en
BOOL LEnQueue(LinkQueue* const Q, ElemType elem) {
    QNode *temp = (QNode*)malloc(sizeof(QNode));
    if(!temp) exit(-1);
    // 
    if(Q->front == Q->rear) {
        (Q->front)->next = temp;
    }
    (Q->rear)->next = temp;
    Q->rear = temp;

    temp->date = elem;
    temp->next = NULL;
    (Q->front)->date++;
}
// out
BOOL LDeQueue(LinkQueue* const Q, ElemType *elem) {
    // null?
    if(Q->front == Q->rear) {
        return FALSE;
    }
    QNode *q = Q->front->next;
    *elem = q->date;
    (Q->front)->next = q->next;
    if(q == Q->rear) {
        Q->rear = Q->front;
    }
    free(q);
    q = NULL;
    (Q->front)->date--;
    return TRUE;
}
