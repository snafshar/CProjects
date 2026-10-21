#include <iostream>
#include <vector>

int linear_search(const std::vector<int>& values, int target) {
    for (std::size_t i = 0; i < values.size(); ++i)
        if (values[i] == target) return static_cast<int>(i);
    return -1;
}
int main() {
    const std::vector<int> values{4, 8, 1, 6};
    std::cout << linear_search(values, 1) << '\n';
}