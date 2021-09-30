#include "stdio.h"

#include "LinkList.h"
#include "DLinkList.h"
#include "CLinkList.h"
// LinkList
void test01() {
    LinkList L;
    LNode *node;
    // ͷ��
    // L = ListHeadInsert(&L);
    // β��
    ListTailInsert(&L);
    TraverList(&L);
    // ����Ų���ֵ
    // node = GetElem(&L, 8);
    // if(node == NULL) {
    //     printf("not found.\n");
    // } else {
    //     printf("get elem: %d\n", node->data);
    // }
    // ��ֵ����
    node = GetValue(&L, 8);
    if(node == NULL) {
        printf("not found.\n");
    } else {
        printf("get elem: %d\n", node->data);
    }
    // ����
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
    // ͷ��
    // L = ListHeadInsert(&L);
    // β��
    DListTailInsert(&L);
    DTraverList(&L);
    // ����Ų���ֵ
    // node = GetElem(&L, 8);
    // if(node == NULL) {
    //     printf("not found.\n");
    // } else {
    //     printf("get elem: %d\n", node->data);
    // }
    // ��ֵ����
    node = DGetValue(&L, 8);
    if(node == NULL) {
        printf("not found.\n");
    } else {
        printf("get elem: %d\n", node->data);
    }
    // ����
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
    // β��
    CListTailInsert(&L);
    CTraverList(&L);
    RCTraverList(&L);
    // ����Ų���ֵ
    node = CGetElem(&L, 2);
    if(node == NULL) {
        printf("not found.\n");
    } else {
        printf("get elem: %d\n", node->data);
    }
    // ��ֵ����
    node = CGetValue(&L, 8);
    if(node == NULL) {
        printf("not found.\n");
    } else {
        printf("get elem: %d\n", node->data);
    }
    // ����
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