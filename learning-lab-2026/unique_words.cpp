#include <iostream>
#include <set>
#include <string>
int main() {
    std::set<std::string> words;
    std::string word;
    while (std::cin >> word) words.insert(word);
    for (const auto& item : words) std::cout << item << '\n';
}