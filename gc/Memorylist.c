#include <stdio.h>
#include <stdlib.h>
#include "../LinkedList/LinkedList.h"
#include "MemoryList.h"

MemoryList memory = (MemoryList){ .head = NULL };
int allocations = 0;
int deletions = 0;

MemoryNode *createMemoryNode(void *data, MemoryNode *next) {
    MemoryNode *newNode = (MemoryNode*)malloc(sizeof(MemoryNode));
    *newNode = (MemoryNode){ .data = data, .next = next };
    return newNode;
}

void append(void *data) {
    memory.head = createMemoryNode(data, memory.head);
    allocations += 1;
}

void deleteAll(MemoryNode *root) {
    if (!root) return;
    free(root->data);
    deleteAll(root->next);
    free(root);
    deletions += 1;
}

void terminate() {
    deleteAll(memory.head);

    //summary of memory management
    printf("%i Allocations and %i Deletions\n", allocations, deletions);
    
    memory.head = NULL;
    allocations = 0;
    deletions = 0;
}

