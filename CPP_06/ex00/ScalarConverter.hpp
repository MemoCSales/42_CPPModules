#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>
# include <math.h>
# include <cstdlib> //atoi
# include <climits> // probably not used
# include <limits>
# include <stdint.h>
# include <sstream>

# define DEBUG 0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT		"\033[0m"

class ScalarConverter {
	private:
		ScalarConverter(void);
	public:
		static void convert(const std::string& literal);
		
};


bool isChar(const std::string& lit);
bool isInt(const std::string& lit);
bool isFloat(const std::string& lit);

void printChar(const std::string& lit);
void printInt(const std::string& lit);
void printFloat(const std::string& lit);

#endif

// #include "ScalarConverter.hpp"

// ++++Constructor
ScalarConverter::ScalarConverter(void) {
	if (DEBUG) {
		std::cout << "ScalarConverter default constructor called" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal) {
	if (isChar(literal))
		printChar(literal);
	else if (isInt(literal))
		printInt(literal);
	else if (isFloat(literal))
		printFloat(literal);
}

bool isChar(const std::string& lit) {
	if (lit.length() == 1 && isprint(lit[0]) && !isdigit(lit[0])) {
		return true;
	}
	return false;	
}

bool isInt(const std::string& lit) {
	if (lit.empty()) {
		return false;
	}

	size_t start = 0;
	if (lit[0] == '+' || lit[0] == '-') {
		start = 1;
	}
	if (start == lit.size()) {
		return false; // String is just a sign, not a valid number
	}
	for (size_t i = start; i < lit.size(); i++)	{
		if (!isdigit(lit[i])) {
			return false;
		}
	}

	// Check range
	char* end;
	long num = std::strtol(lit.c_str(), &end, 10);

	if (*end != '\0' || num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		return false;
	

	return true;
}

bool isFloat(const std::string& lit) {
	if (lit.empty()) return false;

	if (lit[lit.size() - 1] != 'f') return false;

	// Create a substring without the trailing 'f'
	std::string numPart = lit.substr(0, lit.size() - 1);

	// Check if the remaining part has a point
	if (numPart.find('.') == std::string::npos) return false;

	// Check if the remaining part is a valid float
	std::istringstream iss(numPart);
	float num;
	iss >> num;

	// True if the extraction is successful and the end of the string was reach.
	return !iss.fail() && iss.eof();
}

void printChar(const std::string& lit) {
	char c = lit[0];
	std::cout << "char: '" << lit << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	// std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void printInt(const std::string& lit) {
	int num = std::atoi(lit.c_str());

	if (num >= 1 && num <= 127) {
		if (isprint(num)) {
			std::cout << "char: " << static_cast<char>(num) << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		} 
	} else {
		std::cout << "char: impossible" << std::endl;
	}

	std::cout << "int: " << num << std::endl;
	std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void printFloat(const std::string& lit) {
	float floatNum = atof(lit.c_str());

	if (floatNum >= 1 && floatNum <= 127) {
		if (isprint(floatNum)) {
			std::cout << "char: " << static_cast<char>(floatNum) << std::endl;
		} else {
			std::cout << "char: Non displayable" << std::endl;
		}
	} else {
		std::cout << "char: impossible" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(floatNum) << std::endl;
	std::cout << "float: " << static_cast<float>(floatNum) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(floatNum) << std::endl;

	//check nan, +inf, -inf

}