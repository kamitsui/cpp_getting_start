#include <iostream>
#include <string> // std::string, std::string::size_type

// ANSIエスケープシーケンスの色コード定義 (C++98互換)
const char *RESET_COLOR = "\033[0m";
const char *GREEN_COLOR = "\033[32m";         // ツリー本体の色
const char *YELLOW_COLOR = "\033[33m";        // 星や一部の装飾
const char *RED_COLOR = "\033[31m";           // 装飾の色
const char *BLUE_COLOR = "\033[34m";          // 装飾の色
const char *MAGENTA_COLOR = "\033[35m";       // 装飾の色
const char *BRIGHT_YELLOW_COLOR = "\033[93m"; // 明るい黄色 (トップスター)
const char *BROWN_COLOR = "\033[33;1m";       // 茶色 (幹) - 黄色を太字に

// ツリーの高さ (最小5, 推奨7以上)
const int TREE_HEIGHT = 10;

// --- ヘルパー関数定義 ---

// 指定された文字を繰り返して出力する関数 (C++98互換)
void print_chars(char c, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << c;
    }
}

// ツリーの装飾文字と色を定義した構造体 (C++98互換)
struct Decoration {
    char chr;
    const char *color;
};

// 装飾のデータ (固定パターン)
// 実際にはもっと複雑なパターンや数にできますが、シンプルに
Decoration decorations[] = {{'o', RED_COLOR},
                            {'*', BLUE_COLOR},
                            {'@', YELLOW_COLOR}, // 明るい黄色と重複するが、装飾用
                            {'O', MAGENTA_COLOR}};
// 配列の要素数を計算 (C++98互換)
const int NUM_DECORATIONS = sizeof(decorations) / sizeof(decorations[0]);

// --- メイン関数 ---
int main() {
    // トップの星
    int max_width = (TREE_HEIGHT * 2) - 1; // 最下段の幅
    int star_padding = (max_width - 1) / 2;

    print_chars(' ', star_padding);
    std::cout << BRIGHT_YELLOW_COLOR << "*" << RESET_COLOR << std::endl; // 明るい黄色の星

    // ツリー本体
    for (int i = 0; i < TREE_HEIGHT; ++i) {
        int num_stars = (i * 2) + 1;
        int padding = (max_width - num_stars) / 2;

        print_chars(' ', padding);

        for (int j = 0; j < num_stars; ++j) {
            // 装飾を配置する固定パターン (例: 特定の位置に装飾)
            if ((i == 2 && j == 1) || (i == 4 && j == 5) || (i == 7 && j == 2) || (i == 9 && j == num_stars - 2)) {
                // 装飾のインデックスを固定的に決める
                int decor_idx = (i + j) % NUM_DECORATIONS; // パターン例
                std::cout << decorations[decor_idx].color << decorations[decor_idx].chr << RESET_COLOR;
            } else {
                std::cout << GREEN_COLOR << "*" << RESET_COLOR;
            }
        }
        std::cout << std::endl;
    }

    // 幹
    int trunk_width = (TREE_HEIGHT < 5) ? 1 : 3;  // 高さが低い場合は幹も細く
    int trunk_height = (TREE_HEIGHT < 7) ? 2 : 3; // 高さが低い場合は幹も短く
    int trunk_padding = (max_width - trunk_width) / 2;

    for (int i = 0; i < trunk_height; ++i) {
        print_chars(' ', trunk_padding);
        std::cout << BROWN_COLOR;      // 幹の色
        print_chars('#', trunk_width); // 幹の文字
        std::cout << RESET_COLOR << std::endl;
    }

    // メッセージ
    std::cout << std::endl;
    print_chars(' ', (max_width - (sizeof("Merry Christmas!") - 1)) / 2); // 文字列長からパディング計算
    std::cout << RED_COLOR << "Merry Christmas!" << RESET_COLOR << std::endl;
    print_chars(' ', (max_width - (sizeof("Happy New Year!") - 1)) / 2);
    std::cout << BLUE_COLOR << "Happy New Year!" << RESET_COLOR << std::endl;

    return 0;
}
