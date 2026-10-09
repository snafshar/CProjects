#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    const std::vector<double> samples{10.2, 11.4, 9.8, 12.1, 10.7};
    const double average = std::accumulate(samples.begin(), samples.end(), 0.0) / samples.size();
    const auto [minimum, maximum] = std::minmax_element(samples.begin(), samples.end());
    std::cout << "Average: " << average << " ms\n";
    std::cout << "Min: " << *minimum << " ms\n";
    std::cout << "Max: " << *maximum << " ms\n";
}
