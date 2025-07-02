#include <chrono> // std::chrono::system_clock for seed
#include <iostream>
#include <random> // std::mt19937, std::random_device, std::uniform_int_distribution
#include <string>
#include <vector> // std::vector

// ANSIエスケープシーケンスの色コード定義
const std::string RESET_COLOR = "\033[0m";
const std::string TREE_COLOR = "\033[32m";    // 緑
const std::string TRUNK_COLOR = "\033[33;1m"; // 茶色 (明るい黄色を太字に)
const std::string STAR_COLOR = "\033[93m";    // 明るい黄色 (トップスター)

// 装飾に使う文字と色のペア
struct Decoration {
    char chr;
    std::string color_code;
};

// 装飾のバリエーション
const std::vector<Decoration> decorations = {
    {'o', "\033[31m"}, // 赤
    {'O', "\033[34m"}, // 青
    {'@', "\033[35m"}, // マゼンタ
    {'*', "\033[36m"}, // シアン
    {'$', "\033[96m"}  // 明るいシアン
};

// --- ヘルパー関数 ---

// 文字列を中央揃えで出力するためのパディングを計算する
// (C++98時代はstd::string::size()の戻り値はunsigned longなど固定ではなかったが、現代ではsize_t)
void print_centered(const std::string &text, int total_width, const std::string &color = "") {
    if (total_width <= 0 || text.empty()) {
        std::cout << color << text << RESET_COLOR << std::endl;
        return;
    }
    std::string::size_type text_len = text.length();
    int padding = (total_width - static_cast<int>(text_len)) / 2;
    if (padding < 0)
        padding = 0; // テキストが幅を超える場合

    for (int i = 0; i < padding; ++i) {
        std::cout << ' ';
    }
    std::cout << color << text << RESET_COLOR << std::endl;
}

// --- メイン関数 ---
int main() {
    // 乱数エンジンの初期化
    // std::random_device はエントロピーが不足する場合があるため、
    // std::chrono::system_clock を併用するのが一般的
    std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

    // 装飾のインデックスを選ぶための分布
    std::uniform_int_distribution<int> decor_dist(0, decorations.size() - 1);
    // 装飾を配置するかどうかの確率 (例: 10%の確率で装飾)
    std::uniform_int_distribution<int> placement_dist(1, 10); // 1-10の乱数、1が出たら装飾

    const int TREE_HEIGHT = 15;                       // ツリーの高さ
    const int TRUNK_HEIGHT = 4;                       // 幹の高さ
    const int MAX_TREE_WIDTH = (TREE_HEIGHT * 2) - 1; // 最下段の幅

    // トップの星
    print_centered("*", MAX_TREE_WIDTH, STAR_COLOR);

    // ツリー本体
    for (int i = 0; i < TREE_HEIGHT; ++i) {
        int num_leaf_chars = (i * 2) + 1;
        std::string line = "";
        for (int j = 0; j < num_leaf_chars; ++j) {
            // ランダムに装飾を配置
            if (placement_dist(rng) == 1 && i > 0) { // 最上段以外で1/10の確率で装飾
                Decoration chosen_decor = decorations[decor_dist(rng)];
                line +=
                    chosen_decor.color_code + chosen_decor.chr + RESET_COLOR + TREE_COLOR; // 装飾の後、ツリーの色に戻す
            } else {
                line += "*";
            }
        }
        print_centered(line, MAX_TREE_WIDTH, TREE_COLOR); // 行全体の色は緑
    }

    // 幹
    int trunk_width = (TREE_HEIGHT / 5) + 2; // ツリーの高さに応じて幹の幅を調整
    if (trunk_width > MAX_TREE_WIDTH)
        trunk_width = MAX_TREE_WIDTH; // 幅を超えないように

    for (int i = 0; i < TRUNK_HEIGHT; ++i) {
        std::string trunk_line(trunk_width, '#');
        print_centered(trunk_line, MAX_TREE_WIDTH, TRUNK_COLOR);
    }

    // メッセージ
    std::cout << std::endl;
    print_centered("Merry Christmas!", MAX_TREE_WIDTH, "\033[91m"); // 明るい赤
    print_centered("Happy New Year!", MAX_TREE_WIDTH, "\033[94m");  // 明るい青

    return 0;
}
