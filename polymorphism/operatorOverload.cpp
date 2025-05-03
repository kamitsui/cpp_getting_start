#include <iostream>

class Point {
  public:
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    Point operator+(const Point &other) const { return Point(x + other.x, y + other.y); }
};

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2;                                                 // 演算子のオーバーロードが呼び出される
    std::cout << "p3.x = " << p3.x << ", p3.y = " << p3.y << std::endl; // p3.x = 4, p3.y = 6
    return 0;
}
