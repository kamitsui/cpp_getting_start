#include <iostream>

void print(int n) { std::cout << "Integer: " << n << std::endl; }

void print(double d) { std::cout << "Double: " << d << std::endl; }

void print(const std::string &s) { std::cout << "String: " << s << std::endl; }

int main() {
    print(10);      // Integer: 10
    print(3.14);    // Double: 3.14
    print("Hello"); // String: Hello
    return 0;
}
