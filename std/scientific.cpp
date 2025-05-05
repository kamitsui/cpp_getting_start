#include <iomanip>
#include <iostream>
#include <limits> // std::numeric_limits

int main() {
    float epsilon = std::numeric_limits<float>::epsilon();

    std::cout << "デフォルト形式: " << epsilon << std::endl;

    std::cout << "指数表記 (デフォルト精度): " << std::scientific << epsilon << std::endl;

    std::cout << "指数表記 (8桁精度): " << std::scientific << std::setprecision(7) << epsilon << std::endl;
    // 1.1920929e-07

    std::cout << "指数表記 (6桁精度): " << std::scientific << std::setprecision(5) << epsilon << std::endl;
    // 1.1921e-07

    // デフォルトの浮動小数点数形式に戻す場合
    std::cout << "デフォルト形式に戻す: " << std::defaultfloat << epsilon << std::endl;

    return 0;
}
