#include <stdio.h>
#include <stdlib.h>
#include "gc/MemoryList.h"
#include "CharMatrix/CharMatrix.h"

int main(void) {
    CharMatrix m = createCharMatrix('.', 10, 20);
    CharMatrix n = slice(m, 5, 7, 0, 20);

    printCharMatrix(m);
    printf("\n");
    printCharMatrix(n);
    terminate();
}