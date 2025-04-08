/**
 * @file devide.cpp
 * @brief except tutorial
 *
 * try, catch, std::runtime_error
 */
#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero!");
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 2);
        std::cout << "Result: " << result << std::endl;

        result = divide(10, 0); // ここで例外がスローされる
        std::cout << "Result: " << result << std::endl; // この行は実行されない

    } catch (const std::runtime_error& error) {
        std::cerr << "Caught an exception: " << error.what() << std::endl;
    }

    return 0;
}
