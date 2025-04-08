#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;       // 文字列を格納するポインタ
    size_t len;      // 文字列の長さ

public:
    // 1. Default Constructor (引数なしのコンストラクタ)
    MyString() : str(nullptr), len(0) {
        std::cout << "Default constructor called" << std::endl;
    }

    // 2. Constructor (文字列リテラルを受け取るコンストラクタ)
    MyString(const char* s) : len(std::strlen(s)) {
        str = new char[len + 1];
        std::strcpy(str, s);
        std::cout << "Constructor called with: " << s << std::endl;
    }

    // 3. Copy Constructor (同じクラスのオブジェクトを引数にとるコンストラクタ)
    MyString(const MyString& other) : len(other.len) {
        str = new char[len + 1];
        std::strcpy(str, other.str);
        std::cout << "Copy constructor called" << std::endl;
    }

    // 4. Copy Assignment Operator (同じクラスのオブジェクトを代入する演算子)
    MyString& operator=(const MyString& other) {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) { // 自己代入の防止
            delete[] str;   // 既存のメモリを解放
            len = other.len;
            str = new char[len + 1];
            std::strcpy(str, other.str);
        }
        return *this;
    }

    // 5. Destructor (オブジェクトが破棄される際に呼ばれるデストラクタ)
    ~MyString() {
        std::cout << "Destructor called" << std::endl;
        delete[] str;       // メモリを解放
    }

    // 6. Move Constructor (C++11 以降)
    MyString(MyString&& other) noexcept : str(other.str), len(other.len) {
        std::cout << "Move constructor called" << std::endl;
        other.str = nullptr;   // 所有権の移動
        other.len = 0;
    }

    // 7. Move Assignment Operator (C++11 以降)
    MyString& operator=(MyString&& other) noexcept {
        std::cout << "Move assignment operator called" << std::endl;
        if (this != &other) {
            delete[] str;
            str = other.str;
            len = other.len;
            other.str = nullptr;
            other.len = 0;
        }
        return *this;
    }

    // その他のメンバー関数
    const char* getStr() const { return str; }
    size_t getLen() const { return len; }
};

int main() {
    MyString s1("hello");  // Constructor
    MyString s2 = s1;     // Copy constructor
    MyString s3;           // Default constructor
    s3 = s1;             // Copy assignment operator

    std::cout << "s1: " << s1.getStr() << std::endl;
    std::cout << "s2: " << s2.getStr() << std::endl;
    std::cout << "s3: " << s3.getStr() << std::endl;

    MyString s4 = std::move(s1); // Move constructor (C++11以降)
    std::cout << "s4: " << s4.getStr() << std::endl;
    std::cout << "s1: " << s1.getStr() << std::endl; // s1は空になる

    return 0;
}
