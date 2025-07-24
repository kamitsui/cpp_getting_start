#include <cmath> // Required for nanf
#include <iostream>

int main() {
    float my_nan = std::nanf("");         // Generate a quiet NaN with no payload
    float payload_nan = std::nanf("0xF"); // Generate a quiet NaN with a payload

    std::cout << "Quiet NaN: " << my_nan << std::endl;
    std::cout << "Payload NaN: " << payload_nan << std::endl;

    // To check if a value is NaN, use std::isnan()
    if (std::isnan(my_nan)) {
        std::cout << "my_nan is indeed NaN." << std::endl;
    }

    return 0;
}
