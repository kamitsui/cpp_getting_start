#include <iostream>
#include <string>

void capitalizeString(std::string &str) {
  for (char &c : str) { // Using a reference in a range based for loop.
    if (islower(c)) {
      c = toupper(c);
    }
  }
}

int main() {
  std::string text = "hello world";
  capitalizeString(text);
  std::cout << text << std::endl; // Output: HELLO WORLD
  return 0;
}
// compile
// c++ -std=c++11 capitalizeString_c14.cpp
