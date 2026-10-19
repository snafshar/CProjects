#include <stddef.h>
#include <stdio.h>

static ptrdiff_t linear_search(const int *values, size_t count, int target) {
    for (size_t i = 0; i < count; ++i) {
        if (values[i] == target) return (ptrdiff_t)i;
    }
    return -1;
}

int main(void) {
    const int values[] = {3, 5, 7, 9};
    ptrdiff_t index = linear_search(values, sizeof values / sizeof values[0], 7);
    printf("target=7 index=%td\n", index);
    return index == 2 ? 0 : 1;
}
