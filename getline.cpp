#include <iostream>
#include <string>

/**
 * @brief getline : free function in <string>
 */
int main() {
    std::string line;

    std::cout << "Enter a line of text: ";

    // Read a line from standard input (cin)
    if (std::getline(std::cin, line)) {
        std::cout << "You entered: " << line << std::endl;
    } else {
        std::cerr << "Error reading line." << std::endl;
    }

    return 0;
}
