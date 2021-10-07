#include<stdio.h>
#include<stdlib.h>

#include "Stack.h"



// stack
void test01() {
    Stack S;
    InitStack(&S);
    if(IsEmpty(&S)) {
        printf("EMPTY\n");
    }
    SPush(&S, 'a');
    if(IsEmpty(&S)) {
        printf("EMPTY\n");
    }
    SPush(&S, 'b');
    char ret = '0';
    SPop(&S, &ret);
    printf("ret :%c\n", ret);
}

/* 
    假设一个算术表达式中包含圆括号，方括号，花括号3种类型的括号，编写
    一个算法来判别表达式中的括号是否配对，已字符'\0'作为算数表达式的结束符。
    参数：字符串
    输出：true or false
*/
BOOL IsMatch(char *str) {
    Stack S;
    InitStack(&S);
    int i = 0;
    while (str[i] != '\0') {
        char elem = '0';
        switch (str[i]) {
            case '(': SPush(&S, '(');
                break;
            case '[': SPush(&S, '[');
                break;
            case '{': SPush(&S, '{');
                break;
            case ')': { 
                SPop(&S, &elem);
                if(elem != '(') return FALSE;
                break;}
            case ']': { 
                SPop(&S, &elem);
                if(elem != '[') return FALSE;
                break;}
            case '}': { 
                SPop(&S, &elem);
                if(elem != '{') return FALSE;
                break;}
            default:
                break;
        }
        i++;
    }
    if(IsEmpty(&S)) {
        printf("match\n");
        return TRUE;
    } else {
        printf("not match\n");
        return FALSE;
    }
}


int main() {
    // test01();
    char str1[10] = {'1', '*', '(', '2', '+', '3', ')', '\0'};
    char str2[10] = {'1', '*', '(', '2', '+', '3', ')', ']', '\0'};
    // IsMatch(str1);
    if(IsMatch(str2)) {
        printf("match\n");
    } else {
        printf("not match\n");
    }
    return 0;
}