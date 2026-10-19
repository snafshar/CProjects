#include <stddef.h>
#include <stdio.h>

int main(void) {
    const int values[] = {2, 7, 11, 15};
    const size_t count = sizeof values / sizeof values[0];
    const int target = 9;
    for (size_t i = 0; i < count; ++i) {
        for (size_t j = i + 1; j < count; ++j) {
            if (values[i] + values[j] == target) {
                printf("target=%d indices=%zu,%zu values=%d,%d\n",
                       target, i, j, values[i], values[j]);
                return 0;
            }
        }
    }
    puts("no pair found");
    return 1;
}
