#ifndef M_H_
#define M_H_

typedef struct {
    char **head;
    int height;
    int width;
} CharMatrix;

CharMatrix createCharMatrix(char val, int height, int width);

CharMatrix slice(CharMatrix m, int r1, int r2, int c1, int c2);

void printCharMatrix(CharMatrix m);

#endif // M_H_