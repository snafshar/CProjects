/* Minimal IPv4 prefix validation helper. */
#include <stdio.h>

int valid_prefix(int prefix) {
    return prefix >= 0 && prefix <= 32;
}

int main(void) {
    for (int prefix = 0; prefix <= 32; prefix += 8)
        printf("/%d: valid=%s\n", prefix, valid_prefix(prefix) ? "yes" : "no");
    return 0;
}
