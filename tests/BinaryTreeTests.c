#include <stdio.h>
#include "../gc/MemoryList.h"
#include "../BinaryTree/BinaryTree.h"
#include "../CharMatrix/CharMatrix.h"

int main(void) {
    int arr[9] = { 5, 7, 2, 10, 1, 4, 11, 3, 9 };
    BinaryTree t = fromArray(arr, 9);
    BinaryTree u = eliminate(t, 2);

    traverse(t); printf("\n");
    traverse(u); printf("\n");

    CharMatrix c = prettyPrint(t);
    printCharMatrix(c, '\0');

    terminate();
}