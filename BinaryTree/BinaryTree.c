#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BinaryTree.h"
#include "../gc/MemoryList.h"
#include "../CharMatrix/CharMatrix.h"

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

CharMatrix intToSegment(int n) {
    int digitCount = ceil(log10(n + 0.01)), l = 7 + digitCount;   // "--<>--" == 6, '\0' == 1
    char str[l], tmp[12];
    sprintf(tmp, "%d", n);
    for(int i = 0; i < digitCount; i++) str[i + 3] = tmp[i];
    for(int i = 0; i < 3; i++) {
        str[i] = "--<"[i];
        str[i + 3 + digitCount] = ">--"[i];
    }
    str[l - 1] = '\0';
    return fromString(str);
}

CharMatrix prettyPrintNode(Node *n) {
    if (!n) return (CharMatrix){ .head = NULL, .height = 0, .width = 0 };

    CharMatrix left  = prettyPrintNode(n->left);
    CharMatrix right = prettyPrintNode(n->right);
    CharMatrix currentVal = intToSegment(n->val);

    int width = left.width > right.width ? left.width : right.width;
    CharMatrix padLeft  = horizontalConcat(left,  createCharMatrix(' ', left.height,  width - left.width));
    CharMatrix padRight = horizontalConcat(right, createCharMatrix(' ', right.height, width - right.width));
    CharMatrix leftRight = verticalConcat(padLeft, padRight);

    int height = leftRight.height > currentVal.height ? leftRight.height : currentVal.height;
    CharMatrix valPad = verticalConcat(
        currentVal, 
        createCharMatrix(' ', height - currentVal.height, currentVal.width)
    );
    
    CharMatrix leftRightPad = verticalConcat(
        leftRight, 
        createCharMatrix(' ', height - leftRight.height, leftRight.width)
    );
    
    return horizontalConcat(valPad, leftRightPad);
}

CharMatrix prettyPrint(BinaryTree t) {
    return prettyPrintNode(t.head);
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