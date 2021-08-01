#include <stdio.h>
#include "../gc/MemoryList.h"
#include "../Tri/Tri.h"
#include "../CharMatrix/CharMatrix.h"

int main(void) {
    char names[10][10] = { "pamela", "alfred", "bryan", "bryginia", "zane", "gertrude", "tamil" };
    Tri t = insert(EmptyTri, "albert");
    for (int i = 0; i < 7; i++) {
        t = insert(t, names[i]);
    }
    CharMatrix m = traverse(t);
    printCharMatrix(m, '\0'); printf("\n");

    terminate();
}