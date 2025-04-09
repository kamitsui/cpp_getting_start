#include <iostream>
#include <iomanip>

int	main() {
	int number = 123;
	std::string text = "hello";

	std::cout << "num with setw(10):   |" << std::setw(10) << number << "|" << std::endl;
	std::cout << "str with setw(10):   |" << std::setw(10) << text << "|" << std::endl;


	std::cout << "---------------" << std::endl;
	std::cout << "num default-aligned: |" << std::setw(10) << number << "|" << std::endl;
	std::cout << "num right-aligned  : |" << std::right << std::setw(10) << number << "|" << std::endl;
	std::cout << "num left-aligned   : |" << std::left << std::setw(10) << number << "|" << std::endl;
	std::cout << "not sticky setw(10): |" << std::setw(10) << std::left << number << "|" << number << "|" << std::endl;
	std::cout << "setfill and internal:|" << std::setw(10) << std::setfill('*') << std::internal << number << "|" << std::endl;
	return 0;
}

// Key Manipulators Provided by <iomanip> C++98
// std::setw(n)
// std::setfill(c)
// std::left
// std::right
// std::setprecision(n)
// std::fixed
// std::scientific : ex 1.2345E+01
// std::hex, std::oct, std::dec
// std::internal
