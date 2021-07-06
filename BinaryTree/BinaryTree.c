#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "../gc/MemoryList.h"

Node *createNode(int val, Node *left, Node *right) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    append(newNode);
    *newNode = (Node){ .val = val, .left = left, .right = right };
    return newNode;
}

Node *insertNode(Node *n, int val) {
    if (!n) 
        return createNode(val, NULL, NULL);
    if (val < n->val) 
        return createNode(n->val, insertNode(n->left, val), n->right);
    else
        return createNode(n->val, n->left, insertNode(n->right, val));
}

BinaryTree insert(BinaryTree t, int val) {
    return (BinaryTree){ .head = insertNode(t.head, val) };
}

BinaryTree fromArray(int *arr, int length) {
    BinaryTree newTree = (BinaryTree){ .head = NULL };
    for (int i = 0; i < length; i++) {
        newTree = insert(newTree, arr[i]);
    }
    return newTree;
}

int minNode(Node *n) {      //caution undefined behaviour on empty tree
    if (!n) printf("the minimum does not exist **mean girls reference**");
    if (n->left) return minNode(n->left);
    else return n->val;
}

int min(BinaryTree t) {
    if (!t.head) printf("the minimum does not exist **mean girls reference**");
    return minNode(t.head);
}

Node *eliminateNode(Node *n, int val) {
    if (!n) return NULL;
    if (val > n->val) return createNode(n->val, n->left, eliminateNode(n->right, val));
    if (val < n->val) return createNode(n->val, eliminateNode(n->left, val), n->right);
    if (!n->right) return n->left;
    else {
        int replacement = minNode(n->right);
        return createNode(replacement, n->left, eliminateNode(n->right, replacement));
    }
}
 
BinaryTree eliminate(BinaryTree t, int val) {
    return (BinaryTree){ .head = eliminateNode(t.head, val) };
}

void traverseNode(Node *n) {
    if (!n) return;
    traverseNode(n->left);
    printf("%i ", n->val);
    traverseNode(n->right);
}

void traverse(BinaryTree t) {
    traverseNode(t.head);
}