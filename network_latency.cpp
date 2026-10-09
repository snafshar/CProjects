#include <chrono>
#include <iostream>
#include <thread>

int main() {
    constexpr int samples = 5;
    double total_ms = 0.0;
    for (int i = 0; i < samples; ++i) {
        auto start = std::chrono::steady_clock::now();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        auto stop = std::chrono::steady_clock::now();
        double ms = std::chrono::duration<double, std::milli>(stop-start).count();
        total_ms += ms;
        std::cout << "Sample " << i+1 << ": " << ms << " ms\n";
    }
    std::cout << "Average: " << total_ms/samples << " ms\n";
}
