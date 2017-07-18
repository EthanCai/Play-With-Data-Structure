#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

int Fbi(int i) {    /* 斐波那契的递归函数 */
    if (i < 2)
        return i == 0 ? 0 : 1;

    return Fbi(i - 1) + Fbi(i - 2);  /* 这里Fbi就是函数自己，等于在调用自己 */
}

int Fbi2(int i) {   /* 斐波那契的非递归函数 */
    int p0 = 0;
    int p1 = 1;

    if (i == 0) {
        return p0;
    }

    if (i == 1) {
        return p1;
    }

    int tmp = 0;
    for (int j = 0; j < i - 1; j++) {
        tmp = p0 + p1;
        p0 = p1;
        p1 = tmp;
    }

    return p1;
}

int main() {
    printf("迭代显示斐波那契数列：\n");

    clock_t start = clock();

    int a[40];
    a[0] = 0;
    a[1] = 1;
    printf("%d ", a[0]);
    printf("%d ", a[1]);

    for (int i = 2; i < 40; i++) {
        a[i] = a[i - 1] + a[i - 2];
        printf("%d ", a[i]);
    }
    printf("\n");

    clock_t end = clock();
    printf("耗时: %f us", (double)(end - start));
    printf("\n");
    printf("\n");


    printf("迭代函数显示斐波那契数列：\n");

    start = clock();
    for (int i = 0; i < 40; i++)
        printf("%d ", Fbi2(i));
    printf("\n");

    end = clock();
    printf("耗时: %f us", (double)(end - start));
    printf("\n");
    printf("\n");


    printf("递归显示斐波那契数列：(可以明显地看到递归显示的速度慢，牺牲了性能)\n");
    start = clock();
    for (int i = 0; i < 40; i++)
        printf("%d ", Fbi(i));

    printf("\n");
    end = clock();
    printf("耗时: %f us", (double)(end - start));
    printf("\n");
    printf("\n");

    system("(pause || read) 2>/dev/null");
    return 0;
}

