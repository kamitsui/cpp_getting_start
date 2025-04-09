#include <iostream>

class MyClass {
public:
  MyClass &setValue(int value) {
    this->value = value;
    return *this; // Return a reference to the current object.
  }

  int getValue() const { return value; }

private:
  int value;
};

int main() {
  MyClass obj;
  // obj.setValue(10).getValue(); // chaining example.
  int value;
  std::cin >> value;
  std::cout << obj.setValue(value).getValue() << std::endl;
  return 0;
}
