#include <stdlib.h>
#include "../CharMatrix/CharMatrix.h"
#include "../gc/MemoryList.h"
#include "Tri.h"

const Node *nullLetters[26] = { NULL };
const Node nullNode = (Node) { .end = 0, .letters = nullLetters };
const Tri EmptyTri = (Tri) { .head = &nullNode };

Node *createNode(Node **letters, int end) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    append(newNode);

    Node **newLetters = (Node**)calloc(26, sizeof(Node*));
    append(newLetters);

    for (int i = 0; i < 26; i++) {
        newLetters[i] = letters[i];
    }
    
    *newNode = (Node) { .end = end, .letters = newLetters };
    return newNode;
}

Node *insertNode(Node *root, char *word) {
    if (word[0] == '\0') return createNode(root ? root->letters : nullLetters, 1);
    int idx = word[0] - 'a';
    Node *newNode = createNode(root ? root->letters : nullLetters, root ? root->end : 0);
    newNode->letters[idx] = insertNode(newNode->letters[idx], word + 1);
    return newNode;
}

Tri insert(Tri t, char *word) {
    return (Tri) { .head = insertNode(t.head, word) };
}

CharMatrix traverseNode(Node *root) {
    if (!root) return createCharMatrix(' ', 0, 0);
    CharMatrix output = createCharMatrix(' ', 0, 0);
    if (root->end) output = verticalConcatPad(output, createCharMatrix(' ', 1, 1));
    for(int i = 0; i < 26; i++) {
        CharMatrix tmp = traverseNode(root->letters[i]); 
        CharMatrix apptmp = horizontalConcat(createCharMatrix('a' + i, tmp.height, 1), tmp);
        output = verticalConcatPad(output, apptmp);
    }
    return output;
}

CharMatrix traverse(Tri t) {
    return traverseNode(t.head);
}