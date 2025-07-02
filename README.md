# Overview

This repository is practice code for starting C++ 98

## How to compile
```sh
c++ -Wall -Wextra -Werror -std=c++98 cin.cpp
# or
cppw  # cppw='c++ -Wall -Wextra -Werror -std=c++98': alias subcribe
```

## Story of learning
* cin.cpp, cerr.cpp, fstream.cpp
* getline.cpp
* class_circle.cpp
* this_pointer.cpp
* capitalizeString_c98.cpp
* capitalizeString_c14.cpp

### 時刻＆乱数生成

* [memo](random_time/memo.md)

> C++における乱数生成エンジン
>
> C++98 低品質の`std::random()`, C++11 推奨される`std::shuffle()`
>
> 時刻取得やms, μs, nsの取得、`time_t`の2038年問題など。



## Topic

`getline()` is free function in `<string>` (not menber of `<istream>` class


