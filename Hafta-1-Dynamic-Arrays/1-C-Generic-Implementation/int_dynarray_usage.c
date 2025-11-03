#include <stdio.h>
#include <stdlib.h>
#include "int_dynarray.c" /* using direct include for classroom demo - OK for small examples */

/* Simple usage demo for IntArray
 * - create array
 * - append values
 * - iterate and print
 * - remove an element and show result
 * - delete array
 */
int main(void) {
    IntArray *arr = createArray();
    if (!arr) {
        fprintf(stderr, "Failed to create array\n");
        return 1;
    }

    /* append some values */
    append(arr, 10);
    append(arr, 20);
    append(arr, 30);
    append(arr, 40);

    printf("Initial array (size=%d, capacity=%d):\n", arr->size, arr->capacity);
    for (int i = 0; i < arr->size; ++i) {
        int *v = get(arr, i);
        if (v) printf("  [%d] = %d\n", i, *v);
    }

    /* remove index 1 (value 20) */
    int *removed = removeAt(arr, 1);
    if (removed) {
        printf("Removed value: %d\n", *removed);
        free(removed); /* removeAt returns malloc'd int in this implementation */
    } else {
        printf("Remove failed (invalid index)\n");
    }

    printf("After remove (size=%d):\n", arr->size);
    for (int i = 0; i < arr->size; ++i) {
        int *v = get(arr, i);
        if (v) printf("  [%d] = %d\n", i, *v);
    }

    deleteArray(arr);
    return 0;
}