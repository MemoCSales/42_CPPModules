#include "ScalarConverter.hpp"

// ++++Constructor
ScalarConverter::ScalarConverter(void) {
	if (DEBUG) {
		std::cout << "ScalarConverter default constructor called" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal) {
	if (isChar(literal))
		printChar(literal);
	else if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		printSpecialFloat(literal);
	else if (literal == "nan" || literal == "+inf" || literal == "-inf")
		printSpecialDouble(literal);
	else if (isInt(literal))
		printInt(literal);
	else if (isFloat(literal))
		printFloat(literal);
	else if (isDouble(literal))
		printDouble(literal);
	else
		std::cerr << "Invalid literal: " << literal << std::endl;
}
