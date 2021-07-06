#ifndef BT_H_
#define BT_H_

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct {
    Node *head;
} BinaryTree;

BinaryTree insert(BinaryTree t, int val);

BinaryTree fromArray(int *arr, int length);

BinaryTree eliminate(BinaryTree t, int val);

int        min(BinaryTree t);

void       traverse(BinaryTree t);

#endif