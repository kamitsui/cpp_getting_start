#include <iostream>
#include <limits>
#include <ios> // For std::streamsize

void check(bool ret) {
	std::cout << "--- check() ---" << std::endl;
	std::cout << "std:cin:" << ret << std::endl;
	std::cout << "fail() :" << std::cin.fail() << std::endl;
	std::cout << "bad()  :" << std::cin.bad() << std::endl;
	std::cout << "good() :" << std::cin.good() << std::endl;
	std::cout << "---------------" << std::endl;
}

int main() {
	int	age;
	//while (true) {
	//	std::cout << "Enter your age (an integer): ";
	//	if (std::cin >> age) {
	//		check(true);
	//		// Success full
	//		break;
	//	} else {
	//		check(false);
	//		std::cerr << "Invalid input. Please enter an integer." << std::endl;
	//		std::cin.clear();// Clear the error state
	//		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
	//		//return 1;
	//	}
	//}
	//std::cout << "You age is: " << age << std::endl;

	std::cout << "1th Enter your age (an integer): ";
	while (std::cin >> age) {
		std::cout << "You age is: " << age << std::endl;
	}
	std::cout << "2th Enter your age (an integer): ";
	while (std::cin >> age) {
		std::cout << "You age is: " << age << std::endl;
	}

	//std::cin.clear();// Clear the error state
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input


	char	str[10];
	std::cout << "Enter a string: ";
	std::cin >> str;
	std::cout << "You entered: " << str << std::endl;
	return 0;
}

//
