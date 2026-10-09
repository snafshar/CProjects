#include <array>
#include <cstddef>
#include <iostream>
#include <optional>

template <class T, std::size_t N>
class RingBuffer {
    static_assert(N > 0);
    std::array<T, N> data{};
    std::size_t head = 0, tail = 0, count = 0;

public:
    bool push(const T& value) {
        if (count == N) return false;
        data[tail] = value;
        tail = (tail + 1) % N;
        ++count;
        return true;
    }

    std::optional<T> pop() {
        if (count == 0) return std::nullopt;
        T value = data[head];
        head = (head + 1) % N;
        --count;
        return value;
    }

    std::size_t size() const { return count; }
    bool empty() const { return count == 0; }
};

int main() {
    RingBuffer<int, 4> queue;
    for (int value : {7, 11, 15, 19, 23})
        std::cout << "push " << value << ": "
                  << (queue.push(value) ? "accepted" : "full") << '\n';

    while (auto value = queue.pop())
        std::cout << "pop: " << *value << '\n';
}
