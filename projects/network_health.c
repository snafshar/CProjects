#include <stdio.h>

const char *network_status(double latency_ms, double loss_percent) {
    if (latency_ms < 0 || loss_percent < 0 || loss_percent > 100)
        return "invalid";
    if (loss_percent >= 10 || latency_ms >= 200)
        return "poor";
    if (loss_percent >= 2 || latency_ms >= 100)
        return "degraded";
    return "healthy";
}

int main(void) {
    const double latency = 42.0;
    const double loss = 0.5;
    printf("latency=%.1f ms\n", latency);
    printf("loss=%.1f%%\n", loss);
    printf("status=%s\n", network_status(latency, loss));
    return 0;
}
