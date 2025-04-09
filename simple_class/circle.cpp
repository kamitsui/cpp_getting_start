#include <iostream>

class Circle {
private:
	double radius; // Private data member

public:
	// Public member functions (methods)
	void setRadius(double r)
	{
		if (r >= 0)
			radius = r;
		else
			std::cerr << "Invalid radius." << std::endl;
	}

	double getRadius() const
	{
		return radius;
	}

	double getArea() const
	{
		return 3.14159 * radius * radius;
	}
};

int main(void) {
	Circle myCircle;
	myCircle.setRadius(5.0); // Using public method to set private data
	std::cout << "Radius: " << myCircle.getRadius() << std::endl;
	std::cout << "Area: " << myCircle.getArea() << std::endl;
	// myCircle.radius = 10.0; // Error! Cannot access private member directly
	return 0;
}
