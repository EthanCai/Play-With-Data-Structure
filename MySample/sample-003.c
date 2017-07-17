//
// Created by leeco on 06/07/2017.
//

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main() {
    char* s1 = "abc";
    char* s2 = "abc";

    printf("s1's address is %p\n", (void *)s1);
    printf("s2's address is %p\n", (void *)s2);

    char* s3 = malloc(strlen(s1) + strlen(s2) + 1);

    printf("Before concat, s3 is \"%s\", length is %lu\n", s3, strlen(s3));

    strcat(s3, s1);
    strcat(s3, s2);

    printf("After concat, s3 is \"%s\", length is %lu\n", s3, strlen(s3));
}