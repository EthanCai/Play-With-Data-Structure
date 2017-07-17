//
// Created by leeco on 13/07/2017.
//
#include "stdio.h"
#include "stdlib.h"

#ifdef _WIN64
#include "io.h"
#elif _WIN32
#include "io.h"
#elif __APPLE__
#include "sys/uio.h"
#elif __linux
#include "sys/io.h"
#elif __unix
#include "sys/io.h"
#elif __posix
#include "sys/io.h"
#endif

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;           /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Bool;
typedef char ElemType;        /* ElemType类型根据实际情况而定，这里假设为char */

Status visit(ElemType c) {
    printf("%d\n", c);
    return OK;
}

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LoopLinkList;


Status InitList(LoopLinkList *L) {
    *L = (LoopLinkList) malloc(sizeof(Node)); /* Generates a header node, and causes the L to point to the header node */
    if (!(*L))         /* Memory allocation failure */
        return ERROR;
    (*L)->next = *L;

    return OK;
}

Bool ListEmpty(LoopLinkList L) {
    return L->next == L;
}

int ListLength(LoopLinkList L) {
    if (ListEmpty(L)) {
        return 0;
    }

    int i = 1;
    Node *p = L->next->next;

    while(p != L->next) {
        p = p->next;
        i++;
    }

    return i;
}

Status GetElem(LoopLinkList L, int i, ElemType *e) {
    if (!L) {
        return ERROR;
    }

    int len = ListLength(L);
    if (i <= 0 || i > len) {
        return ERROR;
    }

    int j = 0;
    Node *p = L->next;

    while(j < i) {
        p = p->next;
        j++;
    }

    e = &(p->data);

    return OK;
}

Status ListInsert(LoopLinkList *L, int i, ElemType e) {
    if (i <= 0) {
        return ERROR;
    }

    int j = 0;
    Node *head = (*L)->next;
    Node *p = head;                          // p为要插入位置的前一个node

    while(p->next != head && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p->next == head && j < i - 1) {      // i指向的位置超过列表末尾
        return ERROR;
    }

    Node *nw = (Node*)malloc(sizeof(Node));
    nw->data = e;
    nw->next = p->next;
    p->next = nw;

    if (head == nw->next) {
        *L = nw;
    }

    return OK;
}

Status ListTraverse(LoopLinkList L) {
    if (ListEmpty(L)) {
        return OK;
    }

    Node *p = L->next->next;

    while(p != L->next) {
        visit(p->data);
        p = p -> next;
    }

    return OK;
}

Status ListDelete(LoopLinkList *L, int i) {
    if (i <= 0) {
        return ERROR;
    }

    int j = 0;
    Node *head = (*L)->next;
    Node *p = head;                 // p为要删除node的前一个node

    while(p->next != head && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p->next == head) {          // 注意这一行和ListInsert的区别
        return ERROR;
    }

    Node *deleted = p->next;
    p->next = p->next->next;

    if (p->next == head) {
        *L = p;
    }

    free(deleted);
    return OK;
}

Status ListUpdate(LoopLinkList *L, int i, ElemType e) {
    if (i <= 0) {
        return ERROR;
    }

    int j = 0;
    Node *head = (*L)->next;
    Node *p = head;                 // p为要更新node的前一个node

    while(p->next != head && j < i - 1) {
        p = p->next;
        j++;
    }

    if (p->next == head) {
        return ERROR;
    }

    p->next->data = e;
    return OK;
}

Status ListClear(LoopLinkList *L) {
    if (ListEmpty(*L)) {
        return OK;
    }

    Node *head = (*L)->next;
    Node *p = head;

    while(p->next != head) {
        Node *tmp = p->next;
        p->next = p->next->next;
        free(tmp);
    }

    *L = head;
    return OK;
}

int main() {
    LoopLinkList L;

    InitList(&L);

    if (ListEmpty(L)) {
        printf("List is empty\n");
    } else {
        printf("List is not empty\n");
    }

    ListInsert(&L, 1, 1);
    ListInsert(&L, 2, 2);
    ListInsert(&L, 3, 3);
    ListInsert(&L, 4, 4);
    printf("Inserted Elements:\n");
    ListTraverse(L);

    ListDelete(&L, 5);
    printf("After delete 5th element:\n");
    ListTraverse(L);

    ListDelete(&L, 4);
    printf("After delete 4th element:\n");
    ListTraverse(L);

    ListDelete(&L, 2);
    printf("After delete 2rd element:\n");
    ListTraverse(L);

    ListUpdate(&L, 1, 99);
    printf("After update 1st element:\n");
    ListTraverse(L);

    ListClear(&L);
    printf("After clear list:\n");
    ListTraverse(L);
    if (ListEmpty(L)) {
        printf("List is empty\n");
    } else {
        printf("List is not empty\n");
    }
}