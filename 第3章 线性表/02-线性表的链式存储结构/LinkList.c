#include "stdio.h"
#include "string.h"
#include "ctype.h"
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

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

/* Initial allocation of storage space */
#define MAXSIZE 20
/* Status is a function of the type, and its value is the result of the function of the state code, such as OK, etc. */
typedef int Status;
/* ElemType type according to the actual situation, here is the assumption that int */
typedef int ElemType;

Status visit(ElemType c) {
    printf("%d", c);
    return OK;
}

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;
/* Define LinkList*/
typedef struct Node *LinkList;

/* Initial order linear table */
Status InitList(LinkList *L) {
    *L = (LinkList) malloc(sizeof(Node)); /* Generates a header node, and causes the L to point to the header node */
    if (!(*L)) /* Memory allocation failure */
        return ERROR;
    (*L)->next = NULL; /* Pointer field is empty */

    return OK;
}

/* Initial condition: sequential linear table L already exists. Operation results: if the L is empty, it returns TRUE, otherwise it returns FALSE */
Status ListEmpty(LinkList L) {
    if (L->next)
        return FALSE;
    else
        return TRUE;
}

/* Initial condition: sequential linear table L already exists. Operation result: reset the L to an empty table */
Status ClearList(LinkList *L) {
    LinkList p, q;
    p = (*L)->next;    /* p points to the first node */
    while (p) {    /* Not to the end of the table */
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;    /* Header node pointer field is empty */
    return OK;
}

/* Initial condition: sequential linear table L already exists. Operation results: returns the number of data elements in L */
int ListLength(LinkList L) {
    int i = 0;
    LinkList p = L->next; /* p points to the first node */
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

/* Initial condition: sequential linear table L already exists,1��i��ListLength(L) */
/* Operation result: returns the value of the first I data element in L with e */
Status GetElem(LinkList L, int i, ElemType *e) {
    int j;
    LinkList p; /* Declare a node p */
    p = L->next; /* Let p point to the first node of the LinkList L */
    j = 1; /* j as a counter */
    while (p && j < i) {
        p = p->next; /* when p is not empty or counter j is not equal to i,the cycle continues */
        ++j;
    }
    if (!p || j > i)
        return ERROR; /* The i element does not exist */
    *e = p->data; /* Take the i-th element data */
    return OK;
}

/* Initial condition: sequential linear table L already exists */
/* Operation results: returns the bit sequence of first data elements that are satisfied with the E in the L. */
/* If such a data element does not exist, the return value is 0 */
int LocateElem(LinkList L, ElemType e) {
    int i = 0;
    LinkList p = L->next;
    while (p) {
        i++;
        if (p->data == e)    /* Find such data elements */
            return i;
        p = p->next;
    }
    return 0;
}

/* Initial condition: sequential linear table L already exists,1��i��ListLength(L) */
/* Operation results: insert the new data element E, L length plus 1 before the first I position in the L. */
Status ListInsert(LinkList *L, int i, ElemType e) {
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while (p && j < i) { /* Find the i-th node */
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR; /* The i-th element is not exist*/
    s = (LinkList) malloc(sizeof(Node)); /* Create new node (C language standard function) */
    s->data = e;
    s->next = p->next;    /* Assign the successor node of p to the successor of s */
    p->next = s; /* Assign s to the successor to p */
    return OK;
}

/* Initial condition: sequential linear table L already exists,1��i��ListLength(L) */
/* Operation results: delete the L of the first I data elements, and use e to return its value, the length of the L minus 1 */
Status ListDelete(LinkList *L, int i, ElemType *e) {
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while (p->next && j < i) { /* Traversal to find the i-th elements */
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i)
        return ERROR; /* The i-th elements is not exists */
    q = p->next;
    p->next = q->next; /* Assign the successor node of q to the successor of p */
    *e = q->data; /* Take the data of q node to e */
    free(q); /* Let the system recycle this node, free the memory */
    return OK;
}

/* Initial condition: sequential linear table L already exists */
/* Operation results: the output of each data element in L in turn */
Status ListTraverse(LinkList L) {
    LinkList p = L->next;
    while (p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

/* Randomly create values of n elements, the establishment of a single-stranded linear table with a header node L (Head insertion method) */
void CreateListHead(LinkList *L, int n) {
    LinkList p;
    int i;
    srand((unsigned) time(0));    /* Initialize the random number seed */
    *L = (LinkList) malloc(sizeof(Node));
    (*L)->next = NULL; /* First establish a lead single linked list node */
    for (i = 0; i < n; i++) {
        p = (LinkList) malloc(sizeof(Node)); /* Create new node */
        p->data = rand() % 100 + 1;    /* Randomly generated numbers within 100 */
        p->next = (*L)->next;
        (*L)->next = p; /* Insert the table header */
    }
}

/* Randomly create values of n elements, the establishment of a single-stranded linear table with a header node L (Tail insertion method) */
void CreateListTail(LinkList *L, int n) {
    LinkList p, r;
    int i;
    srand((unsigned) time(0));    /* Initialize the random number seed */
    *L = (LinkList) malloc(sizeof(Node)); /* L is the entire linear table */
    r = *L;    /* R to point to the tail of the node */
    for (i = 0; i < n; i++) {
        p = (Node *) malloc(sizeof(Node)); /* Generate new node */
        p->data = rand() % 100 + 1; /* Randomly generated numbers within 100 */
        r->next = p; /* The pointer of LinkList end terminal node point to the new node */
        r = p; /* Define the current new node as LinkList end terminal node */
    }
    r->next = NULL; /* Indicates the end of the current LinkList */
}

/* Main function  */
int main() {
    LinkList L;
    ElemType e;
    Status i;
    int j, k;
    i = InitList(&L);
    printf("After initialization L:ListLength(L)=%d\n", ListLength(L));
    for (j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    printf("After the header are sequentially inserted into the L 1~5:L.data=");
    ListTraverse(L);

    printf("ListLength(L)=%d \n", ListLength(L));
    i = ListEmpty(L);
    printf("L is enmpty?:i=%d(1:yes 0:no)\n", i);

    i = ClearList(&L);
    printf("After empty L:ListLength(L)=%d\n", ListLength(L));
    i = ListEmpty(L);
    printf("L is empty?:i=%d(1:yes 0:no)\n", i);

    for (j = 1; j <= 10; j++)
        ListInsert(&L, j, j);
    printf("After insert 1~10 in the LinkList L tail:L.data=");
    ListTraverse(L);

    printf("ListLength(L)=%d\n", ListLength(L));

    ListInsert(&L, 1, 0);
    printf("After insert 0 in the LinkList L head:L.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d\n", ListLength(L));

    GetElem(L, 5, &e);
    printf("The value of the 5th element is:%d\n", e);
    for (j = 3; j <= 4; j++) {
        k = LocateElem(L, j);
        if (k)
            printf("The value of the %d-th element:%d\n", k, j);
        else
            printf("No the value of the %d-th element:\n", j);
    }
    k = ListLength(L); /* K as the length of LinkList */
    for (j = k + 1; j >= k; j--) {
        i = ListDelete(&L, j, &e); /* Delete the j-th element */
        if (i == ERROR)
            printf("Failed to delete the %d-th element \n", j);
        else
            printf("Delete the value of the %d-th element: %d\n", j, e);
    }
    printf("Output the elements of L in turn:");
    ListTraverse(L);

    j = 5;
    ListDelete(&L, j, &e); /* Delete the 5th element */
    printf("Delete the value of the %d-th element:%d\n", j, e);

    printf("Output the elements of L in turn:");
    ListTraverse(L);

    i = ClearList(&L);
    printf("\n After empty L:ListLength(L)=%d\n", ListLength(L));
    CreateListHead(&L, 20);
    printf("The overall creation of L elements(Head insertion method):");
    ListTraverse(L);

    i = ClearList(&L);
    printf("\n After delete L:ListLength(L)=%d\n", ListLength(L));
    CreateListTail(&L, 20);
    printf("The overall creation of L elements(Tail insertion method):");
    ListTraverse(L);

    system("(pause || read) 2>/dev/null");
    return 0;
}

























