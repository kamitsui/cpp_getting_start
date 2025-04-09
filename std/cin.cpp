// #include <ios> // For std::streamsize??
#include <cerrno>
#include <cstdio> // For feof
#include <fstream>
#include <iostream>
#include <limits>

void check(bool ret) {
  std::cout << "--- check() ---" << std::endl;
  std::cout << "std:cin:" << ret << std::endl;
  std::cout << "fail() :" << std::cin.fail() << std::endl;
  std::cout << "bad()  :" << std::cin.bad() << std::endl;
  std::cout << "good() :" << std::cin.good() << std::endl;
  std::cout << "---------------" << std::endl;
}

int main() {
  // int age;
  std::string age;
  bool input_successful = false;

  while (!input_successful) {
    std::cout << "Enter your age: ";
    // std::cin >> age;
    std::getline(std::cin, age);

    if (std::cin.good()) {
      input_successful = true;
      std::cout << "You age is: " << age << std::endl;
    } else if (std::cin.eof()) {
      std::cout << "EOF input." << std::endl;
      // Ctrl+D was pressed, clear error flags and ignore remaining input
      std::cin.clear();
      std::clearerr(stdin);
      // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Ctrl + D continue ..." << std::endl;
      break;
      // std::cout << "Trying to read again..." << std::endl;
    } else {
      // Input failed (e.g., non-numeric input)
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a number for your age."
                << std::endl;
    }
  }

  // NG : infinity loop if enter Ctrl + D with no input
  // while (true) {
  //	std::cout << "Enter your age (an integer): ";
  //	if (std::cin >> age) {
  //		check(true);
  //		// Success full
  //		break;
  //	} else {
  //		check(false);
  //		std::cerr << "Invalid input. Please enter an integer." <<
  // std::endl; 		std::cin.clear();// Clear the error state
  //		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
  //'\n'); // Discard invalid input
  //		//return 1;
  //	}
  //}
  // std::cout << "You age is: " << age << std::endl;

  // NG : Don't Enter 2th cin
  // std::cout << "1th Enter your age (an integer): ";
  // while (std::cin >> age) {
  //   std::cout << "You age is: " << age << std::endl;
  // }
  // std::cout << "2th Enter your age (an integer): ";
  // while (std::cin >> age) {
  //   std::cout << "You age is: " << age << std::endl;
  // }

  // std::cin.clear();// Clear the error state
  // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //
  // Discard invalid input

  // Create an std::ifstream
  std::ifstream inputFile("your_file.txt");
  if (inputFile.is_open()) {
    // Proceed with reading from the file
    std::string line;
    while (std::getline(inputFile, line)) {
      // Process each line read from the file
      std::cout << "Read from file: " << line << std::endl;
    }
    inputFile.close(); // Close the file when you're done
  } else {
    std::cerr << "Error opening file." << std::endl;
  }

  std::cout << "Enter a string: ";
  // char str[10] = "first";
  // std::cin >> str;
  std::string str;
  // std::getline(std::cin >> std::ws, str);
  std::getline(std::cin, str);
  std::cout << "You entered: " << str << std::endl;
  return 0;
}

//
