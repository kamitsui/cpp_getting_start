#include <iostream>

// Faile :
// int &localVar() {
//   int var = 42;
//   int &refL = var;
//   return refL;
// }
/**
 * error: reference to stack memory associated with local variable 'var'
 * returned [-Werror,-Wreturn-stack-address]
 * 		return refL;
 *      ^~~~
 */

int &getMax(int &a, int &b) { return (a > b) ? a : b; }

int main() {
  int num1 = 10;
  int num2 = 20;

  int &maxNum =
      getMax(num1, num2); // maxNum refers to the larger of num1 or num2

  maxNum = 30; // Modifies either num1 or num2

  std::cout << "num1: " << num1 << std::endl; // Output: num1: 10
  std::cout << "num2: " << num2 << std::endl; // Output: num2: 30

  //  std::cout << "local: " << localVar() << std::endl;

  return 0;
}
