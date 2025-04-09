#include <iostream>

// 入出力ストリーム
int main()
{
	int	number;
	std::cout << "Enter a number: ";
	//std::cin >> number;
	if ((std::cin >> number) != NULL)
	{
		std::cout << "Invalid input. Please enter a number." << std::endl;
		std::cin.clear();// Clear the error state
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
		return 1;
	};
	std::cout << "You entered: " << number << std::endl;

	char	str[10];
	std::cout << "Enter a string: ";
	std::cin >> str;
	std::cout << "You entered: " << str << std::endl;
	return 0;
}

//
