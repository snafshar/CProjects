#include <stdio.h>
#include <stdlib.h>

static int run_command(const char *command) {
    printf("\n$ %s\n", command);
    fflush(stdout);
    return system(command);
}

int main(void) {
    const char *commands[] = {
        "ip -br addr",
        "ip route",
        "ss -s",
        "cat /proc/net/dev"
    };
    const size_t count = sizeof(commands) / sizeof(commands[0]);

    printf("C Network Diagnostics Monitor\n");
    printf("==============================\n");

    int failures = 0;
    for (size_t i = 0; i < count; ++i)
        if (run_command(commands[i]) != 0) ++failures;

    printf("\nDiagnostics complete. Commands failed: %d\n", failures);
    return failures ? EXIT_FAILURE : EXIT_SUCCESS;
}
