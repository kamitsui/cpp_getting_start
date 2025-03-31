#include <iostream>

int main() {
  int x = 10;
  int &refX = x; // refX is initialized to refer to x

  std::cout << "x: " << x << std::endl;       // Output: x: 10
  std::cout << "refX: " << refX << std::endl; // Output: refX: 10

  refX = 20; // Modifying refX changes x

  std::cout << "x: " << x << std::endl;       // Output: x: 20
  std::cout << "refX: " << refX << std::endl; // Output: refX: 20

  return 0;
}
