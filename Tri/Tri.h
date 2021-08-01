#ifndef TRI_H_ 
#define TRI_H_

#include "../CharMatrix/CharMatrix.h"

typedef struct Node {
    int end;
    struct Node **letters;
} Node;

typedef struct Tri {
    Node *head;
} Tri;

const Node *nullLetters[26];
const Node nullNode;
const Tri EmptyTri;

Tri        insert(Tri t, char *word);

CharMatrix traverse(Tri t);


#endif