#include <stdio.h>
#include <stdlib.h>
#include "CharMatrix.h";
#include "../gc/MemoryList.h";

CharMatrix createCharMatrix(char val, int height, int width) {
    if (height < 0 || width < 0) panic("Invalid dimensions for creating matrix");

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

CharMatrix fromString(char *str) {
    int l = 0;
    while (str[l] != '\0') l += 1;
    CharMatrix newMatix = createCharMatrix(' ', 1, l);
    for(int i = 0; i < l; i++) newMatix.head[0][i] = str[i];
    return newMatix;
}

int validSlice(CharMatrix m, int r1, int r2, int c1, int c2) {
    return r1 >= 0 && r2 >= 0 && c1 >= 0 && c2 >= 0 &&
           r1 <= m.height && r2 <= m.height && c1 <= m.width && c2 <= m.width &&
           r1 < r2 && c1 < c2;
}

CharMatrix slice(CharMatrix m, int r1, int r2, int c1, int c2) {
    if (!validSlice(m, r1, r2, c1, c2)) panic("slice out of bounds\n");
    return (CharMatrix) { .head = &m.head[r1], .height = r2 - r1, .width = c2 - c1 };
}

void mut_replace(CharMatrix to, CharMatrix from, int r, int c) {
    if (from.height == 0 || from.width ==0) return;
    if ( !validSlice(to, r, r + from.height, c, c + from.width) ) panic("cannot replace\n");
    for (int row = r; row < r + from.height; row++) {
        for (int col = c; col < c + from.width; col++) {
            to.head[row][col] = from.head[row - r][col - c];
        }
    }
}

CharMatrix copy(CharMatrix m) {
    CharMatrix newMatrix = createCharMatrix(' ', m.height, m.width);
    mut_replace(newMatrix, m, 0, 0);
    return newMatrix;
}

CharMatrix replace(CharMatrix to, CharMatrix from, int r, int c) {
    if ( !validSlice(to, r, r + from.height, c, c + from.width) ) panic("cannot replace\n");
    CharMatrix newMatrix = copy(to);
    mut_replace(newMatrix, from, r, c);
    return newMatrix;
}

CharMatrix verticalConcat(CharMatrix m1, CharMatrix m2) {
    if (m1.width != m2.width) panic("2nd dimension must match for vertical concat\n");
    CharMatrix newMatrix = createCharMatrix(' ', m1.height + m2.height, m1.width);
    mut_replace(newMatrix, m1, 0, 0);
    mut_replace(newMatrix, m2, m1.height, 0);
    return newMatrix; 
}

CharMatrix horizontalConcat(CharMatrix m1, CharMatrix m2) {
    if (m1.height != m2.height) panic("1st dimension must match for horizontal concat\n");
    CharMatrix newMatrix = createCharMatrix(' ', m1.height, m1.width + m2.width);
    mut_replace(newMatrix, m1, 0, 0);
    mut_replace(newMatrix, m2, 0, m1.width);
    return newMatrix;
}

CharMatrix verticalConcatPad(CharMatrix m1, CharMatrix m2) {
    int width = m1.width > m2.width ? m1.width : m2.width;
    CharMatrix padM1 = horizontalConcat(m1, createCharMatrix(' ', m1.height, width - m1.width));
    CharMatrix padM2 = horizontalConcat(m2, createCharMatrix(' ', m2.height, width - m2.width));
    return verticalConcat(padM1, padM2);
}

CharMatrix horizontalConcatPad(CharMatrix m1, CharMatrix m2) {
    int height = m1.height > m2.height ? m1.height : m2.height;
    CharMatrix padM1 = verticalConcat(m1, createCharMatrix(' ', height - m1.height, m1.width));
    CharMatrix padM2 = verticalConcat(m2, createCharMatrix(' ', height - m2.height, m2.width));
    return horizontalConcat(padM1, padM2);
}

void printCharMatrix(CharMatrix m, char delim) {
    for(int i = 0; i < m.height; i++) {
        for(int j = 0; j < m.width; j++) {
            printf("%c%c", m.head[i][j], delim);
        }
        printf("\n");
    }
}

