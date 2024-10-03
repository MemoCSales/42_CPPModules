#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP
# include <iostream>
# include <string>
# include <iomanip>

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
		static void convert(std::string& literal);
		
};


bool isChar(std::string& lit);
// bool isInt(std::string& lit);

void printChar(std::string& lit);
// void printInt(std::string& lit);

#endif

// #include "ScalarConverter.hpp"

// ++++Constructor
ScalarConverter::ScalarConverter(void) {
	if (DEBUG) {
		std::cout << "ScalarConverter default constructor called" << std::endl;
	}
}

void ScalarConverter::convert(std::string& literal) {
	if (isChar(literal))
		printChar(literal);
	// else if (isInt(literal))
	// 	printInt(literal);
}

bool isChar(std::string& lit) {
	if (lit.length() == 1 && isprint(lit[0]) && !isdigit(lit[0])) {
		return true;
	}
	return false;	
}

void printChar(std::string& lit) {
	char c = lit[0];
	std::cout << "char: '" << lit << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}


// bool isInt(std::string& lit) {

// }
