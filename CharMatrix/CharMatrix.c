#include <stdio.h>
#include <stdlib.h>
#include "CharMatrix.h"
#include "../gc/MemoryList.h"

CharMatrix createCharMatrix(char val, int height, int width) {
    char **arr = calloc(height, sizeof(char*));
    append(arr);

    for(int i = 0; i < height; i++) {
        arr[i] = calloc(width, sizeof(char));
        append(arr[i]);
    }

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            arr[i][j] = val;
        }
    }

    return (CharMatrix) { .head = arr, .height = height, .width = width };
}

int validSlice(CharMatrix m, int r1, int r2, int c1, int c2) {
    return r1 >= 0 && r2 >= 0 && c1 >= 0 && c2 >= 0 &&
           r1 <= m.height && r2 <= m.height && c1 <= m.width && c2 <= m.width &&
           r1 < r2 && c1 < c2;
}

CharMatrix slice(CharMatrix m, int r1, int r2, int c1, int c2) {
    if (!validSlice(m, r1, r2, c1, c2)) {
        printf("slice out of bounds\n");
        terminate();
        exit(1);
    }
    return (CharMatrix) { .head = &m.head[r1], .height = r2 - r1, .width = c2 - c1 };
}

void printCharMatrix(CharMatrix m) {
    for(int i = 0; i < m.height; i++) {
        for(int j = 0; j < m.width; j++) {
            printf("%c ", m.head[i][j]);
        }
        printf("\n");
    }
}

