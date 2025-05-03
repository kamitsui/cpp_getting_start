#include <iostream>

template <typename T> T max(T a, T b) { return (a > b) ? a : b; }

int main() {
    int a = 5, b = 10;
    std::cout << "max(a, b) = " << max(a, b) << std::endl; // int 型の max が生成される
    double x = 3.14, y = 2.71;
    std::cout << "max(x, y) = " << max(x, y) << std::endl; // double 型の max が生成される
    return 0;
}
