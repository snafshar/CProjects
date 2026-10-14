/* Pure helpers for transfer and packet-loss measurements. */
#include <errno.h>
#include <stddef.h>

int throughput_mbps(long bytes, double seconds, double *result) {
    if (bytes < 0 || seconds <= 0.0 || result == NULL) return EINVAL;
    *result = ((double)bytes * 8.0) / seconds / 1000000.0;
    return 0;
}

int packet_loss_percent(long sent, long received, double *result) {
    if (sent < 0 || received < 0 || received > sent || result == NULL) return EINVAL;
    *result = sent == 0 ? 0.0 : ((double)(sent - received) * 100.0 / (double)sent);
    return 0;
}
