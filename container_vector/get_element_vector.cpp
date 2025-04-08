/**
 * @file get_element_vector.cpp
 * @brief Practice code for reference return function
 */

#include <iostream>
#include <vector>

/**
 * C++98 version: Nested type initialization list
 *
 * Compile: 
 * c++ -std=c++98 get_element_vector.cpp
 */

/**
 * @brief 
 *
 * @param matrix
 * @param row
 *
 * @return 
 */
std::vector<int> &getElement(std::vector<std::vector<int> > &matrix, int row) {
  return matrix[row];
}

/**
 * C++98 version: Manually initialize
 *
 */
int main() {
    std::vector<std::vector<int> > myMatrix;

    // Create the inner vectors
    std::vector<int> row1;
    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);

    std::vector<int> row2;
    row2.push_back(4);
    row2.push_back(5);
    row2.push_back(6);

    // Add the inner vectors to the outer vector
    myMatrix.push_back(row1);
    myMatrix.push_back(row2);

    // Access elements (example)
    std::cout << myMatrix[0][1] << std::endl; // Output: 2
 
    // Using the getElement function
    std::vector<int>& myRow = getElement(myMatrix, 0); // Get a reference to the first row

    std::cout << myRow[1] << std::endl;             // Output: 2

    getElement(myMatrix, 1)[2] = 10; // Modify the element at row 1, column 2

    std::cout << myMatrix[1][2] << std::endl;       // Output: 10


    return 0;
}

//
/**
 * C++11 version: Nested type initialization list
 *
 * Compile: 
 * c++ -std=c++11 get_element_vector.cpp
 */
//int main() {
//  std::vector<std::vector<int>> myMatrix = {{1, 2, 3}, {4, 5, 6}};
//  std::vector<int> &row = getElement(myMatrix, 0);
//  row[1] = 10;
//  std::cout << myMatrix[0][1] << std::endl; // Output: 10
//  return 0;
//}
