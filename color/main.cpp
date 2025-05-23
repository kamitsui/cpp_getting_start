#include "Colorizer.h" // 作成したヘッダーファイルをインクルード
#include "colors.h"    // 作成したヘッダーファイルをインクルード
#include <iostream>

// main 以外の関数 : colors.h
void printColoredMessage(const std::string &message) {
    std::cout << ANSI::BLUE << ANSI::BOLD << message << ANSI::RESET << std::endl;
}

// main 以外の関数 : Colorizer.h
void printStatusMessage(const std::string &status, const std::string &message) {
    if (status == "OK") {
        std::cout << Colorizer::green("SUCCESS: ") << message << std::endl;
    } else if (status == "ERROR") {
        std::cout << Colorizer::red("FAILED: ") << message << std::endl;
    } else {
        std::cout << message << std::endl;
    }
}

int main() {
    // colors.h
    {
        std::cout << "--------- color.h ----------" << std::endl;
        std::cout << ANSI::RED << "Hello from main!" << ANSI::RESET << std::endl;
        printColoredMessage("This message is from another function!");
        std::cout << ANSI::BG_GREEN << ANSI::YELLOW << "Background test." << ANSI::RESET << std::endl;
    }
    // Colorizer.h
    {
        std::cout << "--------- Colorizer.h ----------" << std::endl;
        std::cout << Colorizer::red("Hello from main!") << std::endl;
        printStatusMessage("OK", "Task completed successfully.");
        printStatusMessage("ERROR", "Something went wrong.");

        std::cout << Colorizer::colorize("Custom Color", ANSI::BLUE, ANSI::BG_YELLOW) << std::endl;
        std::cout << Colorizer::bold(Colorizer::green("Bold Green Text")) << std::endl;
    }
    return 0;
}
