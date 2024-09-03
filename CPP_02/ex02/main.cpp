#include "Fixed.hpp"

int main(void) {
	{

		Fixed	a;
		Fixed const	b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;
		
		std::cout << Fixed::max(a, b) << std::endl;
	}
	// {
	// 	Fixed	a;
	// 	Fixed	const b(Fixed(5.05f) * Fixed(2));
	// 	std::cout << BLUE << "MY TESTS: " << DEFAULT << std::endl;
	// 	// Basic tests
	// 	std::cout << "Initial value of a: " << a << std::endl;
	// 	std::cout << "Value of b: " << b << std::endl;

	// 	// Increment and Decrement tests
	// 	std::cout << "Prefix increment of a: " << ++a << std::endl;
	// 	std::cout << "Postfix increment of a: " << a++ << std::endl;
	// 	std::cout << "Value of a after postfix increment: " << a << std::endl;
	// 	std::cout << "Prefix decrement of a: " << --a << std::endl;
	// 	std::cout << "Postfix decrement of a: " << a-- << std::endl;
	// 	std::cout << "Value of a after postfix decrement: " << a << std::endl;

	// 	// Arithmetic operations
	// 	Fixed c = Fixed(10);
	// 	Fixed d = Fixed(2.5f);
	// 	std::cout << GREEN << "Arithmetic operations: " << DEFAULT << std::endl;
	// 	std::cout << "Initial value of c: " << c << std::endl;
	// 	std::cout << "Initial value of d: " << d << std::endl;
	// 	std::cout << "Addition: " << c + d << std::endl;
	// 	std::cout << "Subtraction: " << c - d << std::endl;
	// 	std::cout << "Multiplication: " << c * d << std::endl;
	// 	std::cout << "Division: " << c / d << std::endl;

	// 	// Comparison operators
	// 	std::cout << GREEN << "Comparison operations: " << DEFAULT << std::endl;
	// 	std::cout << "c > d: " << (c > d) << std::endl;
	// 	std::cout << "c < d: " << (c < d) << std::endl;
	// 	std::cout << "c >= d: " << (c >= d) << std::endl;
	// 	std::cout << "c <= d: " << (c <= d) << std::endl;
	// 	std::cout << "c == d: " << (c == d) << std::endl;
	// 	std::cout << "c != d: " << (c != d) << std::endl;

	// 	// Min and Max functions
	// 	std::cout << GREEN << "MIN - MAX functions: " << DEFAULT << std::endl;
	// 	std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;
	// 	std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;

	// 	// Conversion functions
	// 	std::cout << GREEN << "Conversion functions: " << DEFAULT << std::endl;
	// 	std::cout << "c as float: " << c.toFloat() << std::endl;
	// 	std::cout << "d as float: " << d.toFloat() << std::endl;
	// 	std::cout << "c as int: " << c.toInt() << std::endl;
	// 	std::cout << "d as int: " << d.toInt() << std::endl;
	// }
	return 0;
}