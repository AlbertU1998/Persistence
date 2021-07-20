#include <stdio.h>
#include <stdlib.h>
#include "gc/MemoryList.h"
#include "CharMatrix/CharMatrix.h"

int main(void) {
    CharMatrix m = createCharMatrix('.', 10, 20);
    CharMatrix n = slice(m, 5, 7, 10, 12);
    CharMatrix o = slice(n, 0, 2, 0, 2);
    CharMatrix p = verticalConcat(o, n);
    CharMatrix q = horizontalConcat(p, p);

    // printCharMatrix(m);
    // printf("\n");
    printCharMatrix(o, ' ');
    printf("\n");
    printCharMatrix(q, ' ');
    printf("\n");

    terminate();
}