#include "stdio.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char* String;

void StrAssign(String t, char *str) {
    *t = *str;
}

void StrCopy(String t, String S) {
    *t = *S;
}

void CleanString(String s) {
    *s = "";
}

Status StringEmpty(String s) {

}

int StrLength(String s) {

}

int StrCompare(String s, String t) {

}

void Concat(String t, String s1, String s2) {

}

void SubString(String sub, String s, int pos, int len) {

}

int Index(String s, String t, int pos) {

}

void Replace(String s, String t, String v) {

}

void StrInsert(String s, int pos, String t) {

}

void StrDelete(String s, int pos, int len) {

}

int main() {

}