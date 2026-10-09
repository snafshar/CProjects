#include <cstdint>
#include <iostream>

struct PacketCounter {
    std::uint64_t sent = 0;
    std::uint64_t received = 0;

    std::uint64_t lost() const { return sent - received; }
};

int main() {
    PacketCounter counter{1000, 982};
    std::cout << "Lost packets: " << counter.lost() << '\n';
}
