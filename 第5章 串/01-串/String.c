#include "stdio.h"
#include "stdlib.h"
#include "stddef.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char *String;

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

Status CleanString(String s) {
    if (s == NULL) {
        return ERROR;
    }

    s[0] = '\0';
    return OK;
}

_Bool StringEmpty(String s) {
    return *(s++) == '\0';
}

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

int StrCompare(String s1, String s2) {
    _Bool isEmpty1 = (s1 == NULL) || *s1 == '\0';
    _Bool isEmpty2 = (s2 == NULL) || *s2 == '\0';

    if (isEmpty1) {
        return isEmpty2 ? 0 : -1;
    } else if (isEmpty2) {
        return 1;
    }

    int i = 0;
    while (1) {
        _Bool isEnd1 = (s1[i] == '\0');
        _Bool isEnd2 = (s2[i] == '\0');

        if (isEnd1 && isEnd2) {
            return 0;
        } else if (isEnd1 && !isEnd2) {
            return -1;
        } else if (!isEnd1 && isEnd2) {
            return 1;
        }

        if (s1[i] > s2[i]) {
            return 1;
        } else if (s1[i] < s2[i]) {
            return -1;
        }

        i++;
    }
}

int Index(String s, String t, int pos) {
    int i = pos;    // 主串s当前字符下标
    int j = 0;      // 子串t当前字符下标

    int len_s = StrLength(s);
    int len_t = StrLength(t);

    while(i < len_s && j < len_t) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;      // 退回到上次匹配首位的下一位
            j = 1;
        }
    }

    if (j > len_t - 1) {
        return i - len_t;
    } else {
        return -1;
    }
}


//void Concat(String t, String s1, String s2) {
//
//}

//void SubString(String sub, String s, int pos, int len) {
//
//}

//void Replace(String s, String t, String v) {
//
//}

//void StrInsert(String s, int pos, String t) {
//
//}

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
    int len = StrLength(s2_1);
    printf("After copy s2_2 to s2_1, s2_1 is \"%s\", s2_1's length is %d\n", s2_1, len);

    _Bool isEmpty = StringEmpty(s2_1);
    printf(isEmpty ? "s2_1 is empty\n" : "s2_1 is not empty\n");

    CleanString(s2_1);
    printf("After clean s2_1, s2_1 is \"%s\"\n", s2_1);
    _Bool isEmpty2 = StringEmpty("");
    printf(isEmpty2 ? "s2_1 is empty\n" : "s2_1 is not empty\n");

    printf("Compare \"\" with \"\": %d\n", StrCompare("", ""));
    printf("Compare \"abcde\" with \"abcde\": %d\n", StrCompare("", ""));
    printf("Compare \"abcde\" with \"abcdef\": %d\n", StrCompare("abcde", "abcdef"));
    printf("Compare \"abcde\" with \"abcdf\": %d\n", StrCompare("abcde", "abcdf"));
    printf("Compare \"abcde\" with \"fedwerd\": %d\n", StrCompare("abcde", "abcdf"));
    printf("Compare \"freiwdj\" with \"ereiwdj\": %d\n", StrCompare("freiwdj", "ereiwdj"));
    printf("Compare \"ezeiwdj\" with \"ereiwdj\": %d\n", StrCompare("freiwdj", "ereiwdj"));
    printf("Compare \"ereiwdjquy71276327163a\" with \"ereiwdj\": %d\n", StrCompare("freiwdj", "ereiwdj"));

    printf("\"abc\" indexOf \"eeefffabc12345\": %d\n", Index("eeefffabc12345", "abc", 0));
    printf("\"abc\" indexOf \"abc12345\": %d\n", Index("abc12345", "abc", 0));
    printf("\"abc\" indexOf \"eeefffabc\": %d\n", Index("eeefffabc", "abc", 0));
    printf("\"abc\" indexOf \"eeefffabc\": %d\n", Index("eeefffabc", "abc", 7));
}