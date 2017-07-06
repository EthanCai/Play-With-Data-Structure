//
// Created by leeco on 05/07/2017.
//

#include "stdio.h"

typedef struct Node {
    int value;
    struct Node *next;
} Node;


int main() {
    Node node;          // 声明node后，不用通过malloc分配内存空间
    node.value = 111;

    printf("node.value is %d\n", node.value);

    // the output will be:
    //      node.value is 111
}