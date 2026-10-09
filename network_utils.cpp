#include <cstdint>
#include <iostream>

double packet_loss_percent(std::uint64_t sent, std::uint64_t received) {
    if (received > sent) return -1.0;
    return sent == 0 ? 0.0 : 100.0 * static_cast<double>(sent - received) / sent;
}

int main() {
    std::cout << "Packet loss: " << packet_loss_percent(100, 97) << "%\n";
}
