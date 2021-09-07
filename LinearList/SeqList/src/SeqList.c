#include "SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//  initial
void InitList(SeqList* const L) {
    L->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    if(!L->data) {
        printf("初始化线性表失败.\n");
        return;
    }
    L->length = 0;
    L->MaxSize = MAXSIZE;
}
//  insert seqList
void InsertElem(SeqList* const L, int pos, ElemType elem) {
    // 判断pos是否合法
    if(pos<1 || pos>L->length+1) {
        printf("SeqInsertElem's pos is illegal!\n");
        return;
    } 
    // 判断空间是否足够
    if(L->length >= MAXSIZE) {
        ElemType *p = (ElemType*)realloc(L->data, (L->MaxSize+1)*sizeof(ElemType));
        if(!p) {
            printf("The space is insufficient!\n");
            return;
        }
        L->data = p;
        L->MaxSize++;
    }
    // 插入
    for(int j = L->length; j>=pos; j--) {
        L->data[j] = L->data[j-1];
    }
    L->data[pos-1] = elem;
    L->length++;
}

//  删除线性表元素
void DeleteList(SeqList* const L, int pos, ElemType* const elem) {
     //  检查位序是否合法
    if(pos<1 || pos>L->length+1) {
        printf("SqInsertElem's pos is illegal!\n");
        return;
    }
    //  delete
    *elem = L->data[pos-1];
    for(int i = pos; i<=L->length;i++) {
        L->data[i-1] = L->data[i];
    }
    L->length--;
}
//  返回线性表的长度
int ListLength(const SeqList* const L) {
    printf("The length of SeqList is :%d\n", L->length);
    return L->length;
}
//  查找元素，返回其位序
int LocateElem(const SeqList* const L, ElemType elem) {
    for(int i = 0; i<L->length;i++) {
        if(L->data[i] == elem) {
            return i+1;
        }
    }
    printf("There is No element in SeqList --\n");
    return -1;
}
//  获取指定位序上的元素
int GetElem(const SeqList* const L, int pos) {
    //  检查pos合法性
    if(pos<1 || pos>L->length+1) {
        printf("SqInsertElem's pos is illegal!\n");
        return -1;
    }
    return L->data[pos-1];
}

//  判断线性表是否为空
BOOL ListIsEmpty(const SeqList* const L) {
    if(L->length<1) {
        return TRUE;
    }
    return FALSE;
}
//  销毁线性表--记得释放指针
void DestroyList(SeqList* L) {
    L->length = 0;
    L->MaxSize = 0;
    free(L->data);
    L->data = NULL;
}
//  遍历线性表
void TraverseList(SeqList* const L) {
    printf("SeqList: ");
    for(int i = 1; i<L->length+1; i++) {
        printf("-->%d",L->data[i-1]);
    }
    printf("\n");
}
// 线性表赋值,循环输入线性表的元素，空格分隔，回车结束输入。
void CreateList(SeqList* const L) {
    if(!L) return;
    printf("\t\tCreatList\n");
    printf("Windows enter Ctrl+Z to end the input.\n");
    ElemType elem = 0;
    int pos = 1;
    while (1)
    {
        int ret = scanf("%d", &elem);
        if(ret==0) {
            printf("input error.\n");
            fflush(stdin);
            return;
        }
        if(ret == EOF) {
            break;
        }
        InsertElem(L, pos, elem);
        pos++;
    }
    // 显示创建的线性表
    printf("The result of CreateList():\n");
    if(ListIsEmpty(L)) {
        printf("List is empty.\n");
        return;
    }
    ListLength(L);
    TraverseList(L);
    printf("---------------------------\n");
}

/*  1.
    从顺序表中删除具有最小值的元素（假设唯一,则首次遇到的最小值）
    并由函数返回被删除元素的值，空出的位置由最后一个元素填补，
    若顺序表为空，则显示出错信息并退出。
*/
ElemType DelMin(SeqList* const L) {
    // 判空
    if(L->length == 0) {
        printf("DeMin() error! List is empty.\n");
        exit(-1);
    }
    int min = L->data[0];
    int index = 0;
    for(int i = 1; i<L->length; i++) {
        if(min > L->data[i]) {
            min = L->data[i];
            index = i;
        }
    }
    L->data[index] = L->data[L->length-1];
    L->length--;
    return min;
}

/*  2.
    将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
    L前半部分元素，与后半部分元素交换
    i=0,i<length/2
    data[i] = data[length-1-i]

*/
void ListReverse(SeqList* const L) {
    ElemType temp = 0;
    for(int i = 0; i<L->length/2; i++) {
        temp = L->data[i];
        L->data[i] = L->data[L->length-1-i];
        L->data[L->length-1-i] = temp;
    }
}
/*  3.
    长度为n的线性表，删除其中所有值为x的数据元素，时间复杂度O(n),空间复杂度O(1)
*/
void ValueDel(SeqList* const L, ElemType elem) {
    
    /* // 00--未把下标联系起来使用
    int pos = 1;
    int sub = 0;
    for(int i = 0; i<L->length; i++) {
        while (L->data[i] == elem)
        {
            i++;
            if(i>L->length) {
                break;
            }
            sub++;
        }
        L->data[pos-1] = L->data[i];
        pos++;
    }
    L->length -= sub;*/

    /*// 01--利用下标--重复复制
    int pos = 0;
    for(int i = 0; i<L->length;i++) {
        if(L->data[i] != elem) {
            L->data[pos] = L->data[i];
            pos++;
        }
    }
    L->length = pos;*/

    // 02--
    int n = 0;
    int i = 0;
    while (i<L->length)
    {
        if(L->data[i] == elem) {
            n++;
        } else {
            L->data[i-n] = L->data[i];// 当前元素向前移动n个位置
        }
        i++;
    }
    L->length -= n;
}
/*  4.
    从有序顺序表中删除其值在给定值s与t之间(s<t)的所有元素，
    若s或t不合理或顺序表为空，则显示出错信息并退出运行。
*/
void ValueDel4(SeqList* const L, ElemType s, ElemType t) {
    if(L->length == 0 || s>=t) {
        printf("参数非法\n");
        exit(-1);
    }
    int i=0, j=0;
    // 寻找值大于等于s的第一个元素
    for(i; i<L->length && L->data[i]<s; i++);
    if(i>= L->length) {
        printf("s t 不合理\n");
        return;
    }
    // 寻找值大于t的第一个元素
    for(j; j<L->length && L->data[j]<=t; j++);
    for(;j < L->length;i++, j++) {
        L->data[i] = L->data[j];
    }
    L->length = i;
}
/*  5.
    从顺序表中删除其值在给定值s与t之间(包含s和t,s<t)的所有元素，
    若s或t不合理或顺序表为空，则显示出错信息并退出运行。
*/
void ValueDel5(SeqList* const L, ElemType s, ElemType t) {
    if(L->length == 0 || s>=t) {
        printf("参数非法\n");
        exit(-1);
    }
    int n = 0;
    for(int i = 0; i<L->length; i++) {
        if(L->data[i] >= s && L->data[i] <= t) {
            n++;
        } else {
            L->data[i-n] = L->data[i];
        }
    }
    L->length -= n;
}

/*  6.
    从有序顺序表中删除所有重复的元素
*/
void DelRepeat(SeqList* const L) {
    int n = 0;
    for(int i = 0; i<L->length; i++) {
        if(L->data[i] == L->data[i+1]) {
            n++;
        } else {
            L->data[i-n] = L->data[i];
        }
    }
    L->length -= n;
    /*
    int i = 0;
    int j = 1;
    for(i,j; j<L->length; j++) {
        if(L->data[i] != L->data[j]) {
            L->data[++i] = L->data[j];
        }
    }
    L->length = i+1;*/
}
/*  7.
    将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表。
    按顺序比较，将小的先插入新的线性表，最后将剩余部分插入。
*/
void MergeList(SeqList* const A, SeqList* const B, SeqList* const C) {
    if((A->length+B->length)>C->MaxSize) {
        printf("C的空间不足\n");
        return;
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while ((i<A->length && j<B->length)) {
       if(A->data[i]<=B->data[j]) {
           C->data[k++] = A->data[i++];
       } else {
           C->data[k++] = B->data[j++];
       }
       
    }
    while (i<A->length) {
        C->data[k++] = A->data[i++];
    }
    while (j<B->length) {
        C->data[k++] = B->data[j++];
    }
    C->length = k;
}