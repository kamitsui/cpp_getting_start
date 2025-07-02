#include <ctime> // for time_t and struct tm (optional, for human readable time)
#include <iostream>
#include <sys/time.h> // for gettimeofday

int main() {
    struct timeval tv;
    gettimeofday(&tv, nullptr); // tz (timezone) は通常nullptrでOK

    long long milliseconds = (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
    long long microseconds = (long long)tv.tv_sec * 1000000 + tv.tv_usec;
    // ナノ秒はgettimeofdayでは直接取得できませんが、マイクロ秒から計算は可能（精度はマイクロ秒まで）
    long long nanoseconds_from_microseconds = (long long)tv.tv_usec * 1000;

    std::cout << "Current time (seconds since epoch): " << tv.tv_sec << std::endl;
    std::cout << "Microseconds from current second: " << tv.tv_usec << std::endl;
    std::cout << "Total milliseconds since epoch: " << milliseconds << std::endl;
    std::cout << "Total microseconds since epoch: " << microseconds << std::endl;
    std::cout << "Nanoseconds (from microseconds, limited by us precision): " << nanoseconds_from_microseconds
              << std::endl;

    // もし秒の部分を人間が読める形に変換したい場合
    time_t rawtime = tv.tv_sec;
    struct tm *ltm = std::localtime(&rawtime); // ローカルタイムに変換
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    std::cout << "Human readable time: " << buffer << "." << tv.tv_usec / 1000 << "ms" << std::endl;

    return 0;
}
