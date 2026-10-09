#include <iostream>

int main() {
    const double bytes = 50e6;
    const double seconds = 4.0;
    const double mbps = bytes * 8.0 / seconds / 1e6;
    std::cout << "Bandwidth: " << mbps << " Mbps\n";
}
