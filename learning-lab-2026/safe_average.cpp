#include <iostream>
#include <vector>

bool average(const std::vector<double>& values, double& result) {
    if (values.empty()) return false;
    double total = 0.0;
    for (double value : values) total += value;
    result = total / static_cast<double>(values.size());
    return true;
}
int main() {
    double result = 0.0;
    if (average({2.0, 4.0, 6.0}, result)) std::cout << result << '\n';
    else std::cerr << "Cannot average an empty collection\n";
}