#include "Colorizer.h"
#include "colors.h"

// Colorizer::red
std::string Colorizer::red(const std::string &text) { return ANSI::RED + text + ANSI::RESET; }

// Colorizer::green
std::string Colorizer::green(const std::string &text) { return ANSI::GREEN + text + ANSI::RESET; }

// Colorizer::bold
std::string Colorizer::bold(const std::string &text) { return ANSI::BOLD + text + ANSI::RESET; }

// Colorizer::bgColor
std::string Colorizer::bgColor(const std::string &text, const std::string &bgColorCode) {
    return bgColorCode + text + ANSI::RESET;
}

// Colorizer::colorize
std::string Colorizer::colorize(const std::string &text, const std::string &colorCode, const std::string &bgColorCode) {
    std::string result = "";
    if (!bgColorCode.empty()) {
        result += bgColorCode;
    }
    result += colorCode;
    result += text;
    result += ANSI::RESET;
    return result;
}
