#include <cstdlib>  // std::rand, std::srand, RAND_MAX
#include <ctime>    // std::time
#include <iostream> // std::cout, std::endl
#include <string>   // std::string

// ANSIエスケープコードの色定義
// C++98ではconstexprがないため、const char* で定義
const char *RESET_COLOR = "\033[0m";
const char *RED = "\033[31m";
const char *GREEN = "\033[32m";
const char *YELLOW = "\033[33m";
const char *BLUE = "\033[34m";
const char *MAGENTA = "\033[35m";
const char *CYAN = "\033[36m";
const char *BRIGHT_RED = "\033[91m";
const char *BRIGHT_GREEN = "\033[92m";
const char *BRIGHT_YELLOW = "\033[93m";
const char *BRIGHT_BLUE = "\033[94m";
const char *BRIGHT_MAGENTA = "\033[95m";
const char *BRIGHT_CYAN = "\033[96m";

// 色の配列
const char *COLORS[] = {RED,        GREEN,        YELLOW,        BLUE,        MAGENTA,        CYAN,
                        BRIGHT_RED, BRIGHT_GREEN, BRIGHT_YELLOW, BRIGHT_BLUE, BRIGHT_MAGENTA, BRIGHT_CYAN};
const int NUM_COLORS = sizeof(COLORS) / sizeof(COLORS[0]);

// 指定されたインデントと長さで文字列を中央揃えするヘルパー関数
// C++98なのでstringは使わずchar配列で対応するが、今回は簡単のためstringで。
// 本来はchar*とsnprintfなどを使うべき
void printCentered(const std::string &text, int width) {
    int padding = (width - text.length()) / 2;
    for (int i = 0; i < padding; ++i) {
        std::cout << " ";
    }
    std::cout << text << std::endl;
}

int main() {
    // 乱数の種を設定（プログラム開始時に一度だけ）
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const int tree_height = 15;                      // ツリーの高さ (星と幹を除く葉の部分)
    const int max_width = (tree_height - 1) * 2 + 1; // ツリーの最大幅 (一番下の行のアスタリスクの数)

    // ツリーの星
    std::cout << BRIGHT_YELLOW; // 明るい黄色
    printCentered("  * ", max_width);
    printCentered(" *** ", max_width);
    printCentered("*****", max_width);
    std::cout << RESET_COLOR;

    // ツリーの葉の部分
    for (int i = 0; i < tree_height; ++i) {
        std::string line = "";
        int num_stars = i * 2 + 1;
        int num_spaces = (max_width - num_stars) / 2;

        // 左側のスペース
        for (int s = 0; s < num_spaces; ++s) {
            line += " ";
        }

        // 星と飾り
        for (int j = 0; j < num_stars; ++j) {
            // 約10%の確率で飾りを配置
            if (std::rand() % 10 == 0) {                    // 1/10 の確率
                line += COLORS[std::rand() % NUM_COLORS];   // ランダムな色
                line += (std::rand() % 2 == 0) ? "O" : "o"; // 大文字Oか小文字o
                line += RESET_COLOR;                        // 色をリセット
            } else {
                line += GREEN; // ツリーの色 (緑)
                line += "*";
                line += RESET_COLOR; // 色をリセット
            }
        }

        // 右側のスペースは不要、coutが自動で改行

        std::cout << line << std::endl;
    }

    // ツリーの幹
    std::cout << YELLOW;          // 黄色 (茶色がないので近い色)
    for (int i = 0; i < 3; ++i) { // 幹の高さ
        printCentered("|||", max_width);
    }
    std::cout << RESET_COLOR;

    std::cout << std::endl;
    std::cout << BRIGHT_GREEN << "   Happy Holidays from C++98!   " << RESET_COLOR << std::endl;

    return 0;
}
