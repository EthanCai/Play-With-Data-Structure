//
// Created by ethancai on 04/07/2017.
// 测试结构体作为函数行参，是copy value的方式，还是传入结构体指针
//

#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void visit1(Node node) {
    node.value = 999;       // 传入的是实参的副本
    printf("Visit1: node.value = %d\n", node.value);
}

void visit2(Node *node) {
    (*node).value = 888;    // 传入是实参的指针
    printf("Visit2: node.value = %d\n", (*node).value);
}

int main() {

    Node* n = (Node*) malloc(sizeof(Node));
    (*n).value = 1;

    visit1(*n);
    printf("n.value is %d\n", n->value);        // n->value 写法同 (*n).value

    visit2(n);
    printf("n.value is %d\n", n->value);

    printf("\n");
}