#pragma once
#define ElemType int
#define MAX_SIZE 1
#define BOOL int
#define TRUE 1
#define FALSE 0



// À≥–Ú¥Ê¥¢¿‡–Õ
typedef struct {
    /* data */
    ElemType *data;
    int top;  
} SeqStack;

// initailize
void Initailize(SeqStack* const S);
// ≈–ø’
BOOL StackIsEmpty(SeqStack S);
// PUSH
BOOL Push(SeqStack* const S, ElemType elem);
// POP
BOOL Pop(SeqStack* const S, ElemType* const elem);
// GetTop
BOOL GetTop(SeqStack S, ElemType* const elem);

