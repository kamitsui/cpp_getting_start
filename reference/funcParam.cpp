#include <iostream>

void modifyValue(int &val) { val = 100; }

int main() {
  int y = 50;
  modifyValue(y); // y is passed by reference

  std::cout << "y: " << y << std::endl; // Output: y: 100

  return 0;
}
