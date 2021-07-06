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

typedef struct {
    LinkedList left;
    LinkedList right;
} ListPair;

Node       *createNode(int val, Node *next);

LinkedList  appendToHead(LinkedList root, int val);

LinkedList  fromArray(int *arr, int length);

Node       *conNode(Node *left, Node *right);

LinkedList  concatenate(LinkedList left, LinkedList right);

Node       *takeNode(int n, Node *node);

LinkedList  take(int n, LinkedList l);

Node       *dropNode(int n, Node *node);

LinkedList  drop(int n, LinkedList l);

int         head(LinkedList l);

LinkedList  tail(LinkedList l);

int         last(LinkedList l);

Node        *initNode(Node *n);

LinkedList  init(LinkedList l);

int         length(LinkedList l);

Node       *filterLessNode(int val, Node *n);

LinkedList  filterLess(int val, LinkedList l);

Node       *filterMoreNode(int val, Node *n);

LinkedList  filterMore(int val, LinkedList l);

LinkedList  quicksort(LinkedList l);

Node       *mergeNode(Node *left, Node *right);

LinkedList  merge(LinkedList l, LinkedList r);

LinkedList  mergeSort(LinkedList l);

void        printNode(Node *n);

void        printList(LinkedList l);

#endif // FOO_H_