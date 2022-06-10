#include <iostream>
#include <set>
#include <vector>

int main() {
    int x = 1;
    auto x_plus_n = [&x](int n) -> int { return x +n; };
    int testRes = x_plus_n(2);
    std::cout << "Hello, World!" << std::endl;

    std::set<int> to_remove = {7, 8, 9};
    std::vector<int> digits = {3, 9, 1, 8, 4, 7, 1};

    auto container = std::remove_if(digits.begin(), digits.end(), [&to_remove](int i)
    {
        return to_remove.find(i) != to_remove.end();
    });
    digits.erase(container, digits.end());
    return 0;
}
