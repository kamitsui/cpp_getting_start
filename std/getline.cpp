#include <iostream>
#include <string>

/**
 * @brief getline : free function in <string>
 */
//int main()
//{
//    std::string line;// String data type
//
//    std::cout << "Enter a line of text: ";
//
//    // Read a line from standard input (cin)
//    if (std::getline(std::cin, line))
//        std::cout << "You entered: " << line << std::endl;
//    else
//        std::cerr << "Error reading line." << std::endl;
//
//    return (0);
//}
// getline store string to line from filestream(std::cin)
// std::cin : read from input file stream (exclude \n)

/**
 * @brief loop until eof
 */
int main(void)
{
	std::string line;// String data type

	std::cout << "Enter a line of text: ";

	// Loop getline until EOF or Ctrl+D
	while (std::getline(std::cin, line))
		std::cout << "You entered: " << line << std::endl;

	return (0);
}
