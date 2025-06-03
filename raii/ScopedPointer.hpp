#ifndef SCOPED_POINTER_HPP
#define SCOPED_POINTER_HPP

#include <iostream> // デバッグ出力用
#include <sstream>  // C++98 でポインタアドレスを文字列に変換するため
#include <string>   // std::string のために必要 (LOG_MSGに文字列結合で必要)

// ログ出力用のマクロや関数が定義されたヘッダーをインクルード（仮定）
// 例: #include "Logger.hpp"

// ログ出力マクロの定義（Logger.hppからコピーまたはLogger.hppをインクルード）
// ※もしLogger.hppを既にインクルードしているなら、以下の重複は削除してください
#ifdef DEBUG_MODE
#define LOG_INFO(msg) std::cout << "[INFO]    " << msg << std::endl
#define LOG_WARNING(msg) std::cerr << "[WARNING] " << msg << std::endl
#define LOG_ERROR(msg) std::cerr << "[ERROR]   " << msg << std::endl
#else
#define LOG_INFO(msg)                                                                                                  \
    do {                                                                                                               \
    } while (0)
#define LOG_WARNING(msg)                                                                                               \
    do {                                                                                                               \
    } while (0)
#define LOG_ERROR(msg)                                                                                                 \
    do {                                                                                                               \
    } while (0)
#endif

// テンプレートクラスとして定義
template <typename T> class ScopedPointer {
  private:
    T *m_ptr; // 管理する生ポインタ

    // コピーコンストラクタとコピー代入演算子を禁止
    // これにより、所有権のコピーを防ぎ、二重解放を回避する
    ScopedPointer(const ScopedPointer &);            // 宣言のみ
    ScopedPointer &operator=(const ScopedPointer &); // 宣言のみ

  public:
    // コンストラクタ: 生ポインタを受け取り、所有権を持つ
    explicit ScopedPointer(T *ptr = 0) : m_ptr(ptr) {
        // C++98 でポインタアドレスを文字列に変換する
        std::ostringstream oss;
        oss << static_cast<void *>(m_ptr); // void* にキャストしてアドレスを文字列に
        LOG_INFO("ScopedPointer::Constructor [" + oss.str() + "] created.");
    }

    // デストラクタ: スコープを抜けるときに管理下のメモリを解放
    ~ScopedPointer() {
        std::ostringstream oss;
        oss << static_cast<void *>(m_ptr); // void* にキャストしてアドレスを文字列に
        LOG_INFO("ScopedPointer::Destructor [" + oss.str() + "] destroyed. Deleting resource.");
        delete m_ptr;
    }

    // 生ポインタへのアクセスを提供する
    T *get() const { return m_ptr; }

    // ポインタのように Dereference 演算子 (*) をオーバーロード
    T &operator*() const {
        // null ポインタの場合は未定義動作になるが、通常は呼び出し側でチェック
        return *m_ptr;
    }

    // ポインタのように Member Access 演算子 (->) をオーバーロード
    T *operator->() const {
        // null ポインタの場合は未定義動作になるが、通常は呼び出し側でチェック
        return m_ptr;
    }

    // 所有権を解放し、生ポインタを返す
    // ポインタを受け取った側が解放の責任を持つ
    T *release() {
        T *temp = m_ptr;
        m_ptr = 0; // null にする (デストラクタで delete しないように)
        LOG_INFO("ScopedPointer::release [" + std::string(static_cast<std::ostringstream *>(oss << temp)->str()) +
                 "] released ownership.");
        return temp;
    }

    // 新しいポインタを割り当て直す（以前のポインタは解放される）
    void reset(T *ptr = 0) {
        std::ostringstream old_oss;
        old_oss << static_cast<void *>(m_ptr);
        std::ostringstream new_oss;
        new_oss << static_cast<void *>(ptr);

        if (m_ptr != ptr) {
            LOG_INFO("ScopedPointer::reset [" + old_oss.str() + "] resetting to [" + new_oss.str() +
                     "]. Deleting old resource.");
            delete m_ptr;
            m_ptr = ptr;
        } else {
            LOG_INFO("ScopedPointer::reset [" + old_oss.str() + "] resetting to same pointer. No action.");
        }
    }
};

#endif // SCOPED_POINTER_HPP
