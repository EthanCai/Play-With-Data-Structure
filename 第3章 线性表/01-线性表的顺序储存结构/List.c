#include "stdio.h"
#include "stdlib.h"

#ifdef __APPLE__
#include "sys/uio.h"
#else
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


typedef int Status;          /* Status is a function of the type, and its value is the result of the function of the state code, such as OK, etc. */
typedef int ElemType;        /* ElemType type according to the actual situation, here is the assumption that int */

/* Output the ElemType */
Status visit(ElemType c) {
    printf("%d ", c);
    return OK;
}

typedef struct {
    ElemType data[MAXSIZE];        /* Array, storage data element */
    int length;                                /* Current length of linear table */
} SqList;

/* Initial order linear list */
Status InitList(SqList *L) {
    L->length = 0;
    return OK;
}

/* Initial condition: sequential linear table L already exists. Operation results: if the L is empty, it returns TRUE, otherwise it returns FALSE */
Status ListEmpty(SqList L) {
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}

/* Initial condition: sequential linear table L already exists. Operation result: reset the L to an empty table */
Status ClearList(SqList *L) {
    L->length = 0;
    return OK;
}

/* Initial condition: sequential linear table L already exists. Operation results: returns the number of data elements in L */
int ListLength(SqList L) {
    return L.length;
}

/* The initial conditions: the linear order of the table L already exists，1≤i≤ListLength(L) */
/*  Operation results: use e to return the value of the first i data elements in the L. Note that the i is the position and the first position of the array is from 0 to begin.*/
Status GetElem(SqList L, int i, ElemType *e) {
    if (L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];

    return OK;
}

/* Initial condition: sequential linear table L already exists */
/* Operation results: returns the bit sequence of first data elements that are satisfied with the E in the L. */
/* If such a data element does not exist, the return value is 0 */
int LocateElem(SqList L, ElemType e) {
    int i;
    if (L.length == 0)
        return 0;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e)
            break;
    }
    if (i >= L.length)
        return 0;

    return i + 1;
}


/* Initial condition: sequential linear table L already exists,1≤i≤ListLength(L)， */
/* Operation results: insert the new data element E before the first i position in the L, L length plus 1 */
Status ListInsert(SqList *L, int i, ElemType e) {
    int k;
    if (L->length == MAXSIZE)  /* Sequential linear table is full */
        return ERROR;
    if (i < 1 || i > L->length + 1)/* When the I is smaller than the first position or is larger than the last one */
        return ERROR;

    if (i <= L->length)        /* Insert the data position is not at the end of the table */
    {
        for (k = L->length - 1; k >= i - 1; k--)  /* 将要插入位置之后的数据元素向后移动一位 */
            L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e;          /* Insert a new element */
    L->length++;

    return OK;
}

/* Initial condition: sequential linear table L already exists，1≤i≤ListLength(L) */
/* Operation results: delete the L of the first i data elements, and use e to return its value, the length of the L minus 1 */
Status ListDelete(SqList *L, int i, ElemType *e) {
    int k;
    if (L->length == 0)               /* Linear list is empty */
        return ERROR;
    if (i < 1 || i > L->length)         /* Delete position is not correct */
        return ERROR;
    *e = L->data[i - 1];
    if (i < L->length)                /* If the delete is not the final location */
    {
        for (k = i; k < L->length; k++)    /* 将删除位置后继元素前移 */
            L->data[k - 1] = L->data[k];
    }
    L->length--;
    return OK;
}

/* Initial condition: sequential linear table L already exists */
/* Operation results: the output of each data element in turn on L */
Status ListTraverse(SqList L) {
    int i;
    for (i = 0; i < L.length; i++)
        visit(L.data[i]);
    printf("\n");
    return OK;
}

void unionL(SqList *La, SqList Lb) {
    int La_len, Lb_len, i;
    ElemType e;
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
    for (i = 1; i <= Lb_len; i++) {
        GetElem(Lb, i, &e);
        if (!LocateElem(*La, e))
            ListInsert(La, ++La_len, e);
    }
}

int main() {

    SqList L;
    ElemType e;
    Status i;
    int j, k;
    i = InitList(&L);
    printf("After L initialization: L.length=%d\n", L.length);
    for (j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    printf("After insert in the L table header from numbers 1~5: L.data=");
    ListTraverse(L);

    printf("L.length=%d \n", L.length);
    i = ListEmpty(L);
    printf("L is empty?: i=%d(1:Yes 0:No)\n", i);

    i = ClearList(&L);
    printf("After empty L: L.length=%d\n", L.length);
    i = ListEmpty(L);
    printf("L is empty: i=%d(1:Yes 0:No)\n", i);

    for (j = 1; j <= 10; j++)
        ListInsert(&L, j, j);
    printf("After insert in the L table footer from numbers 1~10: L.data=");
    ListTraverse(L);

    printf("L.length=%d \n", L.length);

    ListInsert(&L, 1, 0);
    printf("After insert in the L table header number 1 :L.data=");
    ListTraverse(L);
    printf("L.length=%d \n", L.length);

    GetElem(L, 5, &e);
    printf("The value of the fifth elements is : %d\n", e);
    for (j = 3; j <= 4; j++) {
        k = LocateElem(L, j);
        if (k)
            printf("The value of the first %d element is: %d\n", k, j);
        else
            printf("No value for %d element\n", j);
    }


    k = ListLength(L);               /* k for table length */
    for (j = k + 1; j >= k; j--) {
        i = ListDelete(&L, j, &e); /* Delete J-th data */
        if (i == ERROR)
            printf("Delete the first %d  data failed \n", j);
        else
            printf("The order number of the %d element is deleted : %d\n", j, e);
    }
    printf("Output L elements in turn");
    ListTraverse(L);

    j = 5;
    ListDelete(&L, j, &e); /* Delete the fifth data */
    printf("The value of the %d element that is deleted is:%d\n", j, e);

    printf("Output L elements in turn");
    ListTraverse(L);

    //Construct a linear table Lb with 10 numbers
    SqList Lb;
    i = InitList(&Lb);
    for (j = 6; j <= 15; j++)
        i = ListInsert(&Lb, 1, j);

    unionL(&L, Lb);

    printf("The output of the L is combined with the elements of the Lb in turn:");
    ListTraverse(L);

    system("pause");
    return 0;
}
