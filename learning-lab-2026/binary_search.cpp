#include <vector>

int binary_search(const std::vector<int>& sorted, int target) {
    int left = 0;
    int right = static_cast<int>(sorted.size()) - 1;
    while (left <= right) {
        const int middle = left + (right - left) / 2;
        if (sorted[middle] == target) return middle;
        if (sorted[middle] < target) left = middle + 1;
        else right = middle - 1;
    }
    return -1;
}