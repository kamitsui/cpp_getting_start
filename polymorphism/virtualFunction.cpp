#include <iostream>

class Shape {
  public:
    virtual void draw() { std::cout << "Drawing a shape." << std::endl; }
};

class Circle : public Shape {
  public:
    void draw() override { // C++11 以降。C++98 では virtual を記述
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
  public:
    void draw() override { // C++11 以降。C++98 では virtual を記述
        std::cout << "Drawing a square." << std::endl;
    }
};

void renderShape(Shape *s) {
    s->draw(); // 実行時にオブジェクトの型に基づいて適切な draw 関数が呼び出される
}

int main() {
    Shape *shape1 = new Shape();
    Shape *shape2 = new Circle();
    Shape *shape3 = new Square();

    renderShape(shape1); // Drawing a shape.
    renderShape(shape2); // Drawing a circle.
    renderShape(shape3); // Drawing a square.

    delete shape1;
    delete shape2;
    delete shape3;

    return 0;
}
