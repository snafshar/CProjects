#include <stddef.h>
#include <stdio.h>

static size_t unique_sorted(int *values, size_t count) {
    if (count == 0) return 0;
    size_t write = 1;
    for (size_t read = 1; read < count; ++read) {
        if (values[read] != values[write - 1]) values[write++] = values[read];
    }
    return write;
}

int main(void) {
    int values[] = {1, 1, 2, 3, 3, 3, 5};
    size_t count = unique_sorted(values, sizeof values / sizeof values[0]);
    printf("unique:");
    for (size_t i = 0; i < count; ++i) printf(" %d", values[i]);
    putchar('\n');
    return 0;
}
