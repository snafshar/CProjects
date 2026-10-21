#pragma once
#include <stdexcept>
#include <vector>

template <typename T>
class Stack {
public:
    void push(const T& value) { items_.push_back(value); }
    void pop() { if (items_.empty()) throw std::out_of_range("pop from empty stack"); items_.pop_back(); }
    T& top() { if (items_.empty()) throw std::out_of_range("top of empty stack"); return items_.back(); }
    bool empty() const noexcept { return items_.empty(); }
    std::size_t size() const noexcept { return items_.size(); }
private:
    std::vector<T> items_;
};