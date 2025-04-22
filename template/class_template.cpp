#include <iostream>

template <typename T> class MyVector {
  private:
    T *data;
    int size;

  public:
    MyVector(int s) : size(s) { data = new T[size]; }
    ~MyVector() { delete[] data; }
    T &operator[](int index) { return data[index]; }
};

int main() {
    MyVector<int> intVector(10);      // int 型の MyVector
    MyVector<double> doubleVector(5); // double 型の MyVector

    intVector[0] = 1;
    doubleVector[0] = 2.5;

    std::cout << intVector[0] << std::endl;
    std::cout << doubleVector[0] << std::endl;

    return 0;
}
