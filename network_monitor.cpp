#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "C++ Network Diagnostics Monitor\n"
              << "===============================\n";

    const std::vector<std::string> commands{
        "ip -br addr",
        "ip route",
        "ss -s",
        "cat /proc/net/dev"
    };

    int failures = 0;
    for (const auto& command : commands) {
        std::cout << "\n$ " << command << '\n';
        if (std::system(command.c_str()) != 0) ++failures;
    }

    std::cout << "\nDiagnostics complete. Failed commands: " << failures << '\n';
    return failures ? EXIT_FAILURE : EXIT_SUCCESS;
}
