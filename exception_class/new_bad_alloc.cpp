/**
 * @file new_bad_alloc.cpp
 * @brief How to std::bad_alloc
 */
#include <iostream>
#include <new> // std::bad_alloc を使うために必要

int main() {
    int* largeArray = nullptr;

    try {
        largeArray = new int[1000000000]; // 非常に大きな配列を割り当ててみる
        std::cout << "Memory allocated successfully!" << std::endl;
        // ... 配列を使用する処理 ...
        delete[] largeArray;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        // エラー処理を行う
        return 1; // エラーコードを返すなど
    }

    return 0;
}
