#include "../LinkedList/LinkedList.h"
#ifndef ML_H_   /* Include guard */
#define ML_H_

// only exists on the heap
typedef struct MemoryNode {
    Node *data;
    struct MemoryNode *next;
} MemoryNode;

// only exists on the stack
typedef struct {
    MemoryNode *head;
} MemoryList;

MemoryNode *createMemoryNode(Node *data, MemoryNode *next);

void append(Node *data);

void deleteAll(MemoryNode *root);

void terminate();

#endif