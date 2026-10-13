/* Estimate throughput in megabits per second. */
#include <stdio.h>

int main(void) {
    const double bytes = 1250000.0;
    const double seconds = 2.0;
    if (seconds <= 0.0) return 1;
    printf("throughput: %.3f Mbps\n", bytes * 8.0 / seconds / 1000000.0);
    return 0;
}
