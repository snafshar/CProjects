#include <stddef.h>
#include <stdio.h>

int main(void) {
    const int a[2][2] = {{1, 2}, {3, 4}};
    const int b[2][2] = {{5, 6}, {7, 8}};
    int product[2][2] = {{0, 0}, {0, 0}};

    for (size_t row = 0; row < 2; ++row) {
        for (size_t col = 0; col < 2; ++col) {
            for (size_t k = 0; k < 2; ++k) {
                product[row][col] += a[row][k] * b[k][col];
            }
        }
    }
    printf("%d %d\n%d %d\n", product[0][0], product[0][1],
           product[1][0], product[1][1]);
    return 0;
}
