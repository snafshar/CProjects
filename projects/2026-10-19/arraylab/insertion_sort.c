#include <stddef.h>
#include <stdio.h>

static void insertion_sort(int *values, size_t count) {
    for (size_t i = 1; i < count; ++i) {
        int current = values[i];
        size_t position = i;
        while (position > 0 && values[position - 1] > current) {
            values[position] = values[position - 1];
            --position;
        }
        values[position] = current;
    }
}

int main(void) {
    int values[] = {4, -3, 9, 2, 0};
    size_t count = sizeof values / sizeof values[0];
    insertion_sort(values, count);
    printf("sorted:");
    for (size_t i = 0; i < count; ++i) printf(" %d", values[i]);
    putchar('\n');
    return 0;
}
