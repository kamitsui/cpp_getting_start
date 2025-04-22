#include <ctime>
#include <iostream>
#include <vector>

int main() {
    std::cout << "hoge" << std::endl;

    clock_t start = clock();
    std::vector<int> data;
    for (int i = 0; i < 1000000; ++i) {
        data.push_back(i); // 動的にメモリを確保
    }
    clock_t end = clock();

    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "処理時間: " << duration << " 秒" << std::endl;

    return 0;
}
