#include <algorithm> // std::shuffle
#include <chrono>    // std::chrono for a good seed
#include <iostream>
#include <random> // std::mt19937, std::random_device
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "元の順序: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // 高品質な乱数エンジンを作成
    std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

    // std::cout << "mt19937: " << rng << std::endl; // 624個の連続した乱数

    //  for (int i = 0; i < 10; ++i) { // 乱数を１つずつ生成して、合計１０個分出力する
    //      std::uint32_t result = rng();
    //      std::cout << result << std::endl;
    //  }

    // ベクターをシャッフル
    std::shuffle(numbers.begin(), numbers.end(), rng);

    std::cout << "シャッフル後の順序: ";
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
// std::random_device はエントロピー源（ハードウェアに基づいたランダムな数値）
// なければシステム時間などをshuffleのシード値にする。
// std::random_device rd;
// std::cout << "エントロピー: " << rd.entropy() << std::endl;
// std::cout << "rd(): " << rd() << std::endl;
