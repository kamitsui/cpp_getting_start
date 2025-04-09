#include <iostream>
#include <limits>
#include <string>

int main() {
  std::string input;

  std::cout << "enter: ";
  // std::cin >> input;// empty line be able to enter
  std::getline(std::cin, input);
  if (std::cin.eof()) {
    std::cout << "EOF enterd" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  std::cout << "1th: " << input << std::endl;
  // std::cin.clear();
  //  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "enter: ";
  // std::cin >> input;
  std::getline(std::cin, input);
  std::cout << "2th: " << input << std::endl;
  return 0;
}
