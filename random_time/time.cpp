#include <cstdlib> // std::srand
#include <ctime>   // std::time
#include <iostream>
#include <string>
int main() {
    std::cout << "--- time() ---" << std::endl;
    std::cout << time(NULL) << std::endl;
    std::cout << "--- srand() & rand()*5 ---" << std::endl;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; ++i) {
        std::cout << rand() << std::endl;
    }
    return (0);
}
