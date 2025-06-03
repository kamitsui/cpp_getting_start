#include <cstdlib> // EXIT_FAILURE のために必要
#include <iostream>
#include <new> // std::bad_alloc のために必要
#include <string>

// --- カスタムアロケータのグローバル変数 ---
static int g_alloc_counter = 0;
static int g_fail_at_alloc_count = -1; // -1 なら常に成功

// --- new 演算子のオーバーロード (グローバル) ---
// これはC++98互換性を意識した一般的なオーバーロード例
void *operator new(std::size_t size) throw(std::bad_alloc) {
    if (g_fail_at_alloc_count != -1) {
        g_alloc_counter++;
        if (g_alloc_counter >= g_fail_at_alloc_count) {
            std::cerr << "--- Forcing std::bad_alloc at allocation #" << g_alloc_counter << " ---" << std::endl;
            throw std::bad_alloc(); // 意図的に例外をスロー
        }
    }
    // 通常のメモリ割り当てを行う
    // C++98 では std::malloc を使用することが多い
    void *ptr = std::malloc(size);
    if (!ptr) {
        std::cerr << "Actual malloc failure!" << std::endl;
        throw std::bad_alloc(); // 本当に割り当てが失敗した場合
    }
    return ptr;
}

// delete 演算子のオーバーロード (対応する delete も必要)
void operator delete(void *ptr) throw() { std::free(ptr); }

// 仮のクラス定義 (Animal, Dog, Cat など)
// 実際には、これらのクラスのヘッダーファイルをインクルードしてください
class Animal {
  public:
    virtual ~Animal() { std::cout << "Animal destructor called." << std::endl; }
    virtual std::string getType() const { return "Animal"; }
    virtual void makeSound() const { std::cout << "Animal makes a sound." << std::endl; }
};

class Dog : public Animal {
  public:
    virtual ~Dog() { std::cout << "Dog destructor called." << std::endl; }
    virtual std::string getType() const { return "Dog"; }
    virtual void makeSound() const { std::cout << "Woof!" << std::endl; }
};

class Cat : public Animal {
  public:
    virtual ~Cat() { std::cout << "Cat destructor called." << std::endl; }
    virtual std::string getType() const { return "Cat"; }
    virtual void makeSound() const { std::cout << "Meow!" << std::endl; }
};

// 作成したスマートポインタのヘッダーをインクルード
#include "ScopedPointer.hpp"

int main() {
    // ポインタ変数ではなく、ScopedPointer のインスタンスをスタックに作成する
    // これらは main 関数のスコープを抜けるときに自動的に解放される
    ScopedPointer<Animal> meta;
    ScopedPointer<Animal> j;
    ScopedPointer<Animal> i;

    try {
        // --- 割り当て失敗のシミュレーション設定 ---
        g_alloc_counter = 0; // カウンタをリセット
        // 3回目の new (i.reset(new Cat())) で失敗するように設定
        // new Animal()が1回目、new Dog()が2回目、new Cat()が3回目
        g_fail_at_alloc_count = 3;

        // new で割り当てた生ポインタを ScopedPointer オブジェクトのコンストラクタに直接渡す
        // または reset() を使用する
        meta.reset(new Animal()); // 1回目の new (成功)
        j.reset(new Dog());       // 1回目の new (成功)
        i.reset(new Cat());       // 3回目の new (ここで失敗がシミュレートされる)

        // もし C で例外がスローされたとしても、
        // A と B で割り当てられたメモリは、meta と j のデストラクタが
        // 自動的に呼ばれることで解放される。

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();

        // ここで明示的に delete する必要はない
        // delete meta;
        // delete j;
        // delete i;

    } catch (const std::bad_alloc &e) {
        std::cerr << "Error: Memory allocation failed! " << e.what() << std::endl;
        // 例外捕捉後、ScopedPointer のデストラクタが自動で呼ばれ、
        // 既に割り当てたメモリが解放されることが保証される。
        return EXIT_FAILURE;
    } catch (const std::exception &e) {
        std::cerr << "An unexpected standard error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return EXIT_FAILURE;
    }

    // main 関数が終了するとき、meta, j, i の ScopedPointer オブジェクトがスコープを抜ける。
    // その際にそれぞれのデストラクタが呼ばれ、内部の生ポインタが指すメモリが解放される。

    return 0;
}
