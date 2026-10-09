#include <cstddef>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

int main() {
    constexpr std::size_t n = 100000;
    constexpr std::size_t workers = 4;
    std::vector<int> values(n, 1);
    std::vector<long long> partial(workers, 0);
    std::vector<std::thread> threads;

    for (std::size_t worker = 0; worker < workers; ++worker) {
        threads.emplace_back([&, worker] {
            const std::size_t begin = worker * n / workers;
            const std::size_t end = (worker + 1) * n / workers;
            partial[worker] = std::accumulate(values.begin() + begin,
                                              values.begin() + end, 0LL);
        });
    }

    for (auto& thread : threads) thread.join();
    const long long total = std::accumulate(partial.begin(), partial.end(), 0LL);
    std::cout << "Elements: " << n << "\nTotal: " << total << '\n';
}
