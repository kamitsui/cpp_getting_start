/**
 * @file openFile.cpp
 * @brief 
 */
#include <stdexcept>
#include <iostream>
#include <fstream>

void openFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    // ファイルを処理するコード
    std::cout << "File opened successfully!" << std::endl;
}

int main() {
    try {
        openFile("nonexistent_file.txt");
    } catch (const std::runtime_error& error) {
        std::cerr << "Error: " << error.what() << std::endl;
    }
    return 0;
}
