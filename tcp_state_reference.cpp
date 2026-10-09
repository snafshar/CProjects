#include <array>
#include <iostream>
#include <string_view>

int main() {
    constexpr std::array<std::string_view, 4> states{
        "LISTEN", "SYN-SENT", "ESTABLISHED", "TIME-WAIT"
    };
    for (auto state : states) std::cout << state << '\n';
}
