#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include "io.h"
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
	printf("%d",c);
	return OK;
}

typedef struct Node {
	ElemType data;
	struct Node *next;
}Node;
/* Define LinkList*/
typedef struct Node *LinkList;

/* Initial order linear table */
Status InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node)); /* Generates a header node, and causes the L to point to the header node */
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
	p = (*L)->next;	/* p points to the first node */
	while (p) {	/* Not to the end of the table */
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;	/* Header node pointer field is empty */
	return OK;
}

/* Initial condition: sequential linear table L already exists. Operation results: returns the number of data elements in L */
int ListLength(LinkList L) {
	int i=0;
	LinkList p = L->next; /* p points to the first node */
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

/* Initial condition: sequential linear table L already exists,1¡Üi¡ÜListLength(L) */
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
	if (!p || j>i)
		return ERROR; /* The i element does not exist */
	*e = p->data; /* Take the i-th element data */
	return OK;
}

/* Initial condition: sequential linear table L already exists */
/* Operation results: returns the bit sequence of first data elements that are satisfied with the E in the L. */
/* If such a data element does not exist, the return value is 0 */
int locateElem(LinkList L, ElemType e) {
	int i = 0;
	LinkList p = L->next;
	while (p) {
		i++;
		if (p->data == e)	/* Find such data elements */
			return i;
		p = p->next;
	}
	return 0;
}

/* Initial condition: sequential linear table L already exists,1¡Üi¡ÜListLength(L) */
/* Operation results: insert the new data element E, L length plus 1 before the first I position in the L. */
Status ListInsert(LinkList *L, int i, ElemType e) {
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while(p && j<i)
}