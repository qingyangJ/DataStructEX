#include "stdio.h"

#include "LinkList.h"
#include "DLinkList.h"
#include "CLinkList.h"
// LinkList
void test01() {
    LinkList L;
    LNode *node;
    // 头插
    // L = ListHeadInsert(&L);
    // 尾插
    ListTailInsert(&L);
    TraverList(&L);
    // 按序号查找值
    // node = GetElem(&L, 8);
    // if(node == NULL) {
    //     printf("not found.\n");
    // } else {
    //     printf("get elem: %d\n", node->data);
    // }
    // 按值查找
    node = GetValue(&L, 8);
    if(node == NULL) {
        printf("not found.\n");
    } else {
        printf("get elem: %d\n", node->data);
    }
    // 插入
    InsertElem(&L, 1, 99);
    DelElem(&L, 2);
    TraverList(&L);
    int ret = ListLength(&L);
    printf("length:  %d", ret);
}
// DLinkList
void test02() {
    DLinkList L;
    DNode *node;
    // 头插
    // L = ListHeadInsert(&L);
    // 尾插
    DListTailInsert(&L);
    DTraverList(&L);
    // 按序号查找值
    // node = GetElem(&L, 8);
    // if(node == NULL) {
    //     printf("not found.\n");
    // } else {
    //     printf("get elem: %d\n", node->data);
    // }
    // 按值查找
    node = DGetValue(&L, 8);
    if(node == NULL) {
        printf("not found.\n");
    } else {
        printf("get elem: %d\n", node->data);
    }
    // 插入
    DInsertElem(&L, 1, 99);
    DDelElem(&L, 2);
    DTraverList(&L);
    int ret = DListLength(&L);
    printf("length:  %d", ret);
}
// CLinkList
void test03() {
    CLinkList L;
    CNode *node;
    // 尾插
    CListTailInsert(&L);
    CTraverList(&L);
    RCTraverList(&L);
    // 按序号查找值
    node = CGetElem(&L, 2);
    if(node == NULL) {
        printf("not found.\n");
    } else {
        printf("get elem: %d\n", node->data);
    }
    // 按值查找
    node = CGetValue(&L, 8);
    if(node == NULL) {
        printf("not found.\n");
    } else {
        printf("get elem: %d\n", node->data);
    }
    // 插入
    // CInsertElem(&L, 1, 99);
    CDelElem(&L, 2);
    CTraverList(&L);
    RCTraverList(&L);
    int ret = CListLength(&L);
    printf("length:  %d", ret);
}
int main() {
    
    test02();
    
    return 0;
}