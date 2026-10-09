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

    for (const auto& command : commands) {
        std::cout << "\n$ " << command << "\n";
        std::system(command.c_str());
    }

    std::cout << "\nDiagnostics complete. Read-only monitor.\n";
}
