/* Calculate average latency from a small sample set. */
#include <stdio.h>

int main(void) {
    const double samples[] = {1.2, 1.8, 2.1, 1.5};
    const size_t count = sizeof(samples) / sizeof(samples[0]);
    double total = 0.0;
    for (size_t i = 0; i < count; ++i) total += samples[i];
    printf("average latency: %.3f ms\n", total / count);
    return 0;
}
