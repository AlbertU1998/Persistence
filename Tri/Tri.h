#ifndef TRI_H_ 
#define TRI_H_


typedef struct Node {
    int end;
    Node **letters;
} Node;

typedef struct Tri {
    Node *head;
} Tri;


#endif