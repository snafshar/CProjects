#include <stddef.h>
#include <stdio.h>

int main(void) {
    const int values[] = {4, 8, 1, 9, 5};
    const size_t count = sizeof values / sizeof values[0];
    int minimum = values[0];
    int maximum = values[0];
    long total = 0;

    for (size_t i = 0; i < count; ++i) {
        if (values[i] < minimum) minimum = values[i];
        if (values[i] > maximum) maximum = values[i];
        total += values[i];
    }

    printf("count=%zu min=%d max=%d mean=%.2f\n",
           count, minimum, maximum, (double)total / (double)count);
    return 0;
}
