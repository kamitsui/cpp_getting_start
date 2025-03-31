#include <cctype> // For toupper and islower
#include <iostream>
#include <string>

void capitalizeString(std::string &str) {
  for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
    if (std::islower(*it)) {
      //*it = std::toupper(*it);
      it = NULL;
    }
  }
}

int main() {
  // std::string text = NULL; segumentation fault
  std::string text = "hello world";
  capitalizeString(text);
  std::cout << text << std::endl;
  return 0;
}
