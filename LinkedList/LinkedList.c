#include <stdio.h>
#include <stdlib.h>
#include "../gc/MemoryList.h"
#include "LinkedList.h"

Node *createNode(int val, Node *next) {
    Node *newNode = malloc(sizeof(Node));
    append(newNode); // keep track of allocated memory
    *newNode = (Node) { .val = val, .next = next };
    return newNode;
}

LinkedList appendToHead(LinkedList root, int val) {
    return (LinkedList) { .head = createNode(val, root.head) };
}

LinkedList fromArray(int *arr, int length) {
    LinkedList l = (LinkedList) { .head = NULL };
    for(int i = 0; i < length; i++) {
        l.head = createNode(arr[length - i - 1], l.head);
    }
    return l;
}

Node *conNode(Node *left, Node *right) {
    if (!left && !right) 
        return NULL;
    if (!left)  
        return right;
    else 
        return createNode(left->val, conNode(left->next, right));
}

LinkedList concatenate(LinkedList left, LinkedList right) {
    return (LinkedList) { .head = conNode(left.head, right.head) };
}

Node *takeNode(int n, Node *node) {
    if (n == 0 || !node) return NULL;
    return createNode(node->val, takeNode(n - 1, node->next));
}

LinkedList take(int n, LinkedList l) {
    return (LinkedList) { .head = takeNode(n, l.head) };
}

Node *dropNode(int n, Node *node) {
    if (!node)
        return NULL;
    if (n == 0)
        return node;
    else
        return dropNode(n - 1, node->next);
}

LinkedList drop(int n, LinkedList l) {
    return (LinkedList) { .head = dropNode(n, l.head) };
}

int head(LinkedList l) {    // caution, undefined behaviour on empty lists
    if (!l.head) printf("attmepted to take head of empty list");
    return l.head->val;
}

LinkedList tail(LinkedList l) {
    return (LinkedList){ .head = l.head ? l.head->next : NULL };
}

int last(LinkedList l) { // caution undefined behaviour on empty lists
    if (!l.head->next) return l.head->val;
    return last((LinkedList){ .head = l.head->next });
}

Node *initNode(Node *n) {
    if (!n) return NULL;
    if (!n->next) return NULL;
    return createNode(n->val, initNode(n->next));
}

LinkedList init(LinkedList l) {
    return (LinkedList) { .head = initNode(l.head) };
}

int length(LinkedList l) {
    if (!l.head) return 0;
    return 1 + length((LinkedList){ .head = l.head->next });
}

Node *filterLessNode(int val, Node *n) {
    if (!n) 
        return NULL;
    if (n->val < val) 
        return createNode(n->val, filterLessNode(val, n->next));
    else 
        return filterLessNode(val, n->next);
}

LinkedList filterLess(int val, LinkedList l) {
    return (LinkedList){ .head = filterLessNode(val, l.head) };
}

Node *filterMoreNode(int val, Node *n) {
    if (!n) 
        return NULL;
    if (n->val > val) 
        return createNode(n->val, filterMoreNode(val, n->next));
    else
        return filterMoreNode(val, n->next);
}

LinkedList filterMore(int val, LinkedList l) {
    return (LinkedList){ .head = filterMoreNode(val, l.head) };
}

LinkedList quicksort(LinkedList l) {            // does not work with repeated numbers!!
    if (!l.head) return l;
    int pivot = head(l);
    LinkedList left  = quicksort( filterLess(pivot, tail(l)) );
    LinkedList right = quicksort( filterMore(pivot, tail(l)) );
    return concatenate(left, appendToHead(right, pivot));
}

Node *mergeNode(Node *left, Node *right) {
    if(!left && !right) 
        return NULL;
    if (!left)  
        return createNode(right->val, mergeNode(left, right->next));
    if (!right) 
        return createNode(left->val , mergeNode(left->next, right));
    if (left->val < right->val) 
        return createNode(left->val , mergeNode(left->next, right));
    else
        return createNode(right->val, mergeNode(left, right->next));
}

LinkedList merge(LinkedList l, LinkedList r) {
    return (LinkedList) { .head = mergeNode(l.head, r.head) };
}

LinkedList mergeSort(LinkedList l) {                // again only works with uniqe lists
    int len = length(l);
    if (len < 2) return l;
    LinkedList left  = mergeSort(take(len / 2, l));
    LinkedList right = mergeSort(drop(len / 2, l));
    return merge(left, right);
}

// admin functions ---------------------------------------------

void printNode(Node *n) {
    if (!n) return;
    printf("%i ", n->val);
    printNode(n->next);
}

void printList(LinkedList l) {
    printNode(l.head);
}

// things to implement
// append (tick)
// concatenate (tick)
// take (tick)
// drop (tick)
// head (tick)
// tail (tick)
// length (tick)
// quicksort (tick)
// mergesort (tick)