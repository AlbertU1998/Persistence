#include <stdlib.h>
#include <stdio.h>
#include "LinkedList/LinkedList.h"
#include "gc/MemoryList.h"

int main(void) {
    int arr[9] = { 1, 9, 5, 8, 6, 14, 2, 7, 4 };

    LinkedList l = fromArray(arr, 9);
    LinkedList m = mergeSort(l);
    LinkedList n = init(m);

    printList(l); printf("\n");
    printList(m); printf("\n");
    printList(n); printf("\n");
    printf("%i\n", last(n));
    
    terminate();
}