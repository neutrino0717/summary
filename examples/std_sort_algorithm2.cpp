#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::vector<int> values = { 3, 5, 1, 4, 2 };
    std::sort(values.begin(), values.end());
    for (int value: values) std::cout << value << ' '; std::cout << std::endl;

    std::sort(values.begin(), values.end(), std::less<int>()); //std::greater
    for (int value: values) std::cout << value << ' '; std::cout << std::endl;

    std::sort(values.begin(), values.end(), [](int a, int b){ return a < b; });
    for (int value: values) std::cout << value << ' '; std::cout << std::endl;
}
