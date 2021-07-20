#ifndef ML_H_   /* Include guard */
#define ML_H_

// only exists on the heap
typedef struct MemoryNode {
    void *data;
    struct MemoryNode *next;
} MemoryNode;

// only exists on the stack
typedef struct {
    MemoryNode *head;
} MemoryList;

void append(void *data);

void terminate();

void panic(char *message);

#endif