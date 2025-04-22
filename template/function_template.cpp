#include <iostream>

template <typename T> T max(T a, T b) { return (a > b) ? a : b; }

int main() {
    int x = 5, y = 10;
    double p = 3.14, q = 2.71;

    std::cout << max(x, y) << std::endl; // int 型で呼び出し
    std::cout << max(p, q) << std::endl; // double 型で呼び出し

    return 0;
}
