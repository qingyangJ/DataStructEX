#include "SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//  initial
void InitList(SeqList* const L) {
    L->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    if(!L->data) {
        printf("��ʼ�����Ա�ʧ��.\n");
        return;
    }
    L->length = 0;
    L->MaxSize = MAXSIZE;
}
//  insert seqList
void InsertElem(SeqList* const L, int pos, ElemType elem) {
    // �ж�pos�Ƿ�Ϸ�
    if(pos<1 || pos>L->length+1) {
        printf("SeqInsertElem's pos is illegal!\n");
        return;
    } 
    // �жϿռ��Ƿ��㹻
    if(L->length >= MAXSIZE) {
        ElemType *p = (ElemType*)realloc(L->data, (L->MaxSize+1)*sizeof(ElemType));
        if(!p) {
            printf("The space is insufficient!\n");
            return;
        }
        L->data = p;
        L->MaxSize++;
    }
    // ����
    for(int j = L->length; j>=pos; j--) {
        L->data[j] = L->data[j-1];
    }
    L->data[pos-1] = elem;
    L->length++;
}

//  ɾ�����Ա�Ԫ��
void DeleteList(SeqList* const L, int pos, ElemType* const elem) {
     //  ���λ���Ƿ�Ϸ�
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
//  �������Ա�ĳ���
int ListLength(const SeqList* const L) {
    printf("The length of SeqList is :%d\n", L->length);
    return L->length;
}
//  ����Ԫ�أ�������λ��
int LocateElem(const SeqList* const L, ElemType elem) {
    for(int i = 0; i<L->length;i++) {
        if(L->data[i] == elem) {
            return i+1;
        }
    }
    printf("There is No element in SeqList --\n");
    return -1;
}
//  ��ȡָ��λ���ϵ�Ԫ��
int GetElem(const SeqList* const L, int pos) {
    //  ���pos�Ϸ���
    if(pos<1 || pos>L->length+1) {
        printf("SqInsertElem's pos is illegal!\n");
        return -1;
    }
    return L->data[pos-1];
}

//  �ж����Ա��Ƿ�Ϊ��
BOOL ListIsEmpty(const SeqList* const L) {
    if(L->length<1) {
        return TRUE;
    }
    return FALSE;
}
//  �������Ա�--�ǵ��ͷ�ָ��
void DestroyList(SeqList* L) {
    L->length = 0;
    L->MaxSize = 0;
    free(L->data);
    L->data = NULL;
}
//  �������Ա�
void TraverseList(SeqList* const L) {
    printf("SeqList: ");
    for(int i = 1; i<L->length+1; i++) {
        printf("-->%d",L->data[i-1]);
    }
    printf("\n");
}
// ���Ա�ֵ,ѭ���������Ա��Ԫ�أ��ո�ָ����س��������롣
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
    // ��ʾ���������Ա�
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
    ��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ,���״���������Сֵ��
    ���ɺ������ر�ɾ��Ԫ�ص�ֵ���ճ���λ�������һ��Ԫ�����
    ��˳���Ϊ�գ�����ʾ������Ϣ���˳���
*/
ElemType DelMin(SeqList* const L) {
    // �п�
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
    ��˳���L������Ԫ�����ã�Ҫ���㷨�Ŀռ临�Ӷ�ΪO(1)
    Lǰ�벿��Ԫ�أ����벿��Ԫ�ؽ���
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
    ����Ϊn�����Ա�ɾ����������ֵΪx������Ԫ�أ�ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
*/
void ValueDel(SeqList* const L, ElemType elem) {
    
    /* // 00--δ���±���ϵ����ʹ��
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

    /*// 01--�����±�--�ظ�����
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
            L->data[i-n] = L->data[i];// ��ǰԪ����ǰ�ƶ�n��λ��
        }
        i++;
    }
    L->length -= n;
}
/*  4.
    ������˳�����ɾ����ֵ�ڸ���ֵs��t֮��(s<t)������Ԫ�أ�
    ��s��t�������˳���Ϊ�գ�����ʾ������Ϣ���˳����С�
*/
void ValueDel4(SeqList* const L, ElemType s, ElemType t) {
    if(L->length == 0 || s>=t) {
        printf("�����Ƿ�\n");
        exit(-1);
    }
    int i=0, j=0;
    // Ѱ��ֵ���ڵ���s�ĵ�һ��Ԫ��
    for(i; i<L->length && L->data[i]<s; i++);
    if(i>= L->length) {
        printf("s t ������\n");
        return;
    }
    // Ѱ��ֵ����t�ĵ�һ��Ԫ��
    for(j; j<L->length && L->data[j]<=t; j++);
    for(;j < L->length;i++, j++) {
        L->data[i] = L->data[j];
    }
    L->length = i;
}
/*  5.
    ��˳�����ɾ����ֵ�ڸ���ֵs��t֮��(����s��t,s<t)������Ԫ�أ�
    ��s��t�������˳���Ϊ�գ�����ʾ������Ϣ���˳����С�
*/
void ValueDel5(SeqList* const L, ElemType s, ElemType t) {
    if(L->length == 0 || s>=t) {
        printf("�����Ƿ�\n");
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
    ������˳�����ɾ�������ظ���Ԫ��
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
    ����������˳���ϲ�Ϊһ���µ�����˳������ɺ������ؽ��˳���
    ��˳��Ƚϣ���С���Ȳ����µ����Ա����ʣ�ಿ�ֲ��롣
*/
void MergeList(SeqList* const A, SeqList* const B, SeqList* const C) {
    if((A->length+B->length)>C->MaxSize) {
        printf("C�Ŀռ䲻��\n");
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