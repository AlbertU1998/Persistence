#ifndef M_H_
#define M_H_

typedef struct {
    char **head;
    int height;
    int width;
} CharMatrix;

CharMatrix createCharMatrix(char val, int height, int width);

CharMatrix fromString(char *str);

CharMatrix slice(CharMatrix m, int r1, int r2, int c1, int c2);

CharMatrix replace(CharMatrix to, CharMatrix from, int r, int c);

CharMatrix verticalConcat(CharMatrix m1, CharMatrix m2);

CharMatrix horizontalConcat(CharMatrix m1, CharMatrix m2);

CharMatrix verticalConcatPad(CharMatrix m1, CharMatrix m2);

CharMatrix horizontalConcatPad(CharMatrix m1, CharMatrix m2);

void printCharMatrix(CharMatrix m, char delim);

#endif // M_H_