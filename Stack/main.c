#include<stdio.h>


#include "SeqStack.h"
#include "LinkStack.h"

// SeqStack
void test01() {
    SeqStack S;
    ElemType elem = 100;
    Initailize(&S);
    if (Push(&S, elem))
    {
        printf("PUSHED %d\n", elem);
    }
    if(StackIsEmpty(S)) {
        printf(" STACK IS EMPTY\n");
    }
    if (Push(&S, 200))
    {
        printf("PUSHED %d\n", 200);
    }
    int topElem = 0;
    if(GetTop(S, &topElem)) {
        printf("GetTop: %d\n", topElem);
    }
    int ret = 0;
    if(Pop(&S, &ret)) {
        printf("POPED ELEM: %d\n", ret);
    }
}
// LinkStack
void test02() {
    Stack S;
    ElemType elem = 100;
    LInitailize(&S);
    if (LPush(&S, elem)) {
        printf("PUSHED %d\n", elem);
    }
    if(LStackIsEmpty(S)) {
        printf(" STACK IS EMPTY\n");
    }
    if (LPush(&S, 200)) {
        printf("PUSHED %d\n", 200);
    }
    if (LPop(&S, &elem)) {
        /* code */
        printf(" POP  %d\n", elem);
    }
    
    int topElem = 0;
    if(LGetTop(S, &topElem)) {
        printf("GetTop: %d\n", topElem);
    }
    printf("height: %d\n", S.height);
}


int main() {

    test02();


    return 0;
}
    
