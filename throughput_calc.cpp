#include <iostream>

int main() {
    const double megabytes = 125.0;
    const double seconds = 10.0;
    const double megabitsPerSecond = megabytes * 8.0 / seconds;
    std::cout << "Throughput: " << megabitsPerSecond << " Mbps\n";
}
