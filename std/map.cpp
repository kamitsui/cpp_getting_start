#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> myMap;

    myMap["apple"] = 1;
    myMap["banana"] = 2;
    myMap["cherry"] = 3;

    // add insert() + pair<>() or make_pair()
    myMap.insert(std::pair<std::string, int>("grape", 4));
    myMap.insert(std::make_pair("kiwi", 5));

    // get map["key"] or map.at("key")
    std::cout << "Value of apple: " << myMap["apple"] << std::endl;      // 出力: Value of apple: 1
    std::cout << "Value of banana: " << myMap.at("banana") << std::endl; // 出力: Value of banana: 2

    // iterator : bigin(), end(), it->first, it->second
    for (std::map<std::string, int>::const_iterator it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    // find()
    std::map<std::string, int>::const_iterator it = myMap.find("kiwi");
    if (it != myMap.end()) {
        std::cout << "Found kiwi: " << it->second << std::endl; // 出力: Found kiwi: 5
    } else {
        std::cout << "kiwi not found." << std::endl;
    }

    // erase()
    myMap.erase("banana");             // キーを指定して削除
    myMap.erase(myMap.find("cherry")); // イテレータを指定して削除

    // size()
    std::cout << "Map size: " << myMap.size() << std::endl;
    if (myMap.empty()) {
        std::cout << "Map is empty." << std::endl;
    } else {
        std::cout << "Map is not empty." << std::endl;
    }

    return 0;
}
