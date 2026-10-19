#include <stddef.h>
#include <stdio.h>

static ptrdiff_t binary_search(const int *values, size_t count, int target) {
    size_t left = 0, right = count;
    while (left < right) {
        size_t middle = left + (right - left) / 2;
        if (values[middle] < target) left = middle + 1;
        else right = middle;
    }
    return left < count && values[left] == target ? (ptrdiff_t)left : -1;
}

int main(void) {
    const int values[] = {1, 3, 5, 7, 9};
    ptrdiff_t index = binary_search(values, sizeof values / sizeof values[0], 7);
    printf("target=7 index=%td\n", index);
    return index == 3 ? 0 : 1;
}
