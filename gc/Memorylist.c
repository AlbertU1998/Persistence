#include <stdio.h>
#include <stdlib.h>
#include "../LinkedList/LinkedList.h"
#include "MemoryList.h"

MemoryList memory = (MemoryList){ .head = NULL };

MemoryNode *createMemoryNode(Node *data, MemoryNode *next) {
    MemoryNode *newNode = (MemoryNode*)malloc(sizeof(MemoryNode));
    *newNode = (MemoryNode){ .data = data, .next = next };
    return newNode;
}

void append(Node *data) {
    memory.head = createMemoryNode(data, memory.head);
}

void deleteAll(MemoryNode *root) {
    // printf("deletion\n");
    if (!root) return;
    deleteAll(root->next);
    free(root->data);
    free(root);
}

void terminate() {
    deleteAll(memory.head);
    memory.head = NULL;
}

