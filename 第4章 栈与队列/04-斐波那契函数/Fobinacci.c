#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int Fbi(int i) {    /* 斐波那契的递归函数 */
    if (i < 2)
        return i == 0 ? 0 : 1;
    return Fbi(i - 1) + Fbi(i - 2);  /* 这里Fbi就是函数自己，等于在调用自己 */
}

int main() {
    int i;
    int a[40];
    printf("迭代显示斐波那契数列：\n");
    a[0] = 0;
    a[1] = 1;
    printf("%d ", a[0]);
    printf("%d ", a[1]);
    for (i = 2; i < 40; i++) {
        a[i] = a[i - 1] + a[i - 2];
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("\n");
    printf("两种不同的方式显示斐波那契数列:\n");
    printf("\n");

    printf("递归显示斐波那契数列：(可以明显地看到递归显示的速度慢，牺牲了性能)\n");
    for (i = 0; i < 40; i++)
        printf("%d ", Fbi(i));

    printf("\n");

    system("(pause || read) 2>/dev/null");
    return 0;
}

