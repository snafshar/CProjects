#include <stddef.h>
#include <stdio.h>

static size_t merge(const int *a, size_t na, const int *b, size_t nb, int *out) {
    size_t i = 0, j = 0, k = 0;
    while (i < na && j < nb) out[k++] = a[i] <= b[j] ? a[i++] : b[j++];
    while (i < na) out[k++] = a[i++];
    while (j < nb) out[k++] = b[j++];
    return k;
}

int main(void) {
    const int a[] = {1, 3, 6};
    const int b[] = {2, 4, 8};
    int merged[6];
    size_t count = merge(a, 3, b, 3, merged);
    printf("merged:");
    for (size_t i = 0; i < count; ++i) printf(" %d", merged[i]);
    putchar('\n');
    return 0;
}
