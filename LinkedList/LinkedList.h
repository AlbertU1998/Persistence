#ifndef LL_H_   /* Include guard */
#define LL_H_

// only exists on the heap
typedef struct Node {
    int val;
    struct Node *next;
} Node;

// only exists on the stack
typedef struct {
    Node *head;
} LinkedList;

LinkedList  appendToHead(LinkedList root, int val);

LinkedList  fromArray(int *arr, int length);

LinkedList  concatenate(LinkedList left, LinkedList right);

LinkedList  take(int n, LinkedList l);

LinkedList  drop(int n, LinkedList l);

LinkedList  tail(LinkedList l);

LinkedList  init(LinkedList l);

LinkedList  filterLess(int val, LinkedList l);

LinkedList  filterMore(int val, LinkedList l);

LinkedList  quicksort(LinkedList l);

LinkedList  merge(LinkedList l, LinkedList r);

LinkedList  mergeSort(LinkedList l);

int         length(LinkedList l);

int         last(LinkedList l);

int         head(LinkedList l);

void        printList(LinkedList l);

#endif