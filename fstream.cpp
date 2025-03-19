#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream inputFile("my_file.txt"); // Create an input file stream
	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		    std::cout << line << std::endl;
		inputFile.close();
	}
	else
	    std::cerr << "Unable to open file" << std::endl;
	return 0;
}
