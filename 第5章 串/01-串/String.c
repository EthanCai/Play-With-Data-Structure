#include "stdio.h"
#include "stdlib.h"
#include "stddef.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char *String;

int StrLength(String s);

Status StrAssign(String dest, String src) {

    if (dest == NULL || src == NULL) {
        return ERROR;
    }

    if (dest == src) {
        return OK;
    }

    char *ptr = src;
    int idx = 0;
    while(*ptr != '\0') {
        dest[idx++] = *ptr++;
    }

    dest[idx] = '\0';

    return OK;
}

Status StrCopy(String dest, String src) {

    if (dest == NULL || src == NULL) {
        return ERROR;
    }

    if (dest == src) {
        return OK;
    }

    char* ptrDest = dest;
    char* ptrSrc = src;

    int idx = 0;
    while (*ptrSrc != '\0') {
        ptrDest[idx++] = *ptrSrc++;
    }
    ptrDest[idx] = '\0';

    return OK;
}

Status CleanString(String s) {
    if (s == NULL) {
        return ERROR;
    }

    s[0] = '\0';
    return OK;
}

int StrLength(String s) {
    if (s == NULL) {
        return -1;
    }

    int size = 0;
    while(*s++ != '\0') {
        size++;
    }

    return size;
}

_Bool StringEmpty(String s) {
    return *(s++) == '\0';
}

//int StrCompare(String s, String t) {
//
//}
//
//void Concat(String t, String s1, String s2) {
//
//}
//
//void SubString(String sub, String s, int pos, int len) {
//
//}
//
//int Index(String s, String t, int pos) {
//
//}
//
//void Replace(String s, String t, String v) {
//
//}
//
//void StrInsert(String s, int pos, String t) {
//
//}
//
//void StrDelete(String s, int pos, int len) {
//
//}

int main() {
    String s1 = (String) malloc(10 * sizeof(char));
    StrAssign(s1, "abcde");
    printf("s1 is \"%s\"\n", s1);

    String s2_1 = (String) malloc(20 * sizeof(char));
    String s2_2 = "hello world!";
    StrCopy(s2_1, s2_2);
    printf("s2_1 is %s\n", s2_1);

    _Bool isEmpty = StringEmpty(s2_1);
    printf(isEmpty ? "s2_1 is empty\n" : "s2_1 is not empty\n");

    CleanString(s2_1);
    printf("after clean, s2_1 is \"%s\"\n", s2_1);
    _Bool isEmpty2 = StringEmpty("");
    printf(isEmpty2 ? "s2_1 is empty\n" : "s2_1 is not empty\n");
}