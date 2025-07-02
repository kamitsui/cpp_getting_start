#include <cstdlib> // std::rand, std::srand
#include <ctime>   // std::time
#include <iostream>

int main() {
    // 乱数の種を設定（通常はプログラムの開始時に一度だけ）
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 0 から 99 までのランダムな整数を生成
    int random_number = std::rand() % 100;
    std::cout << "ランダムな数字: " << random_number << std::endl;

    return 0;
}
