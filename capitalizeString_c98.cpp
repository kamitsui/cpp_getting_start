#include <cctype> // For toupper and islower
#include <iostream>
#include <string>

void capitalizeString(std::string &str) {
  for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
    if (std::islower(*it)) {
      *it = std::toupper(*it);
    }
  }
}

int main() {
  std::string text = "hello world";
  capitalizeString(text);
  std::cout << text << std::endl;
  return 0;
}
