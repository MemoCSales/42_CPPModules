#include "RPN.hpp"

// ++++Constructor
RPN::RPN(void) : _stack() {
	if (DEBUG) {
		std::cout << "RPN default constructor called" << std::endl;
	}
}

// Copy Constructor
RPN::RPN(const RPN &other) {
	if (DEBUG) {
		std::cout << "RPN copy constructor called" << std::endl;
	}
	this->_stack = other._stack;
}

// Assignment Operator
RPN &RPN::operator=(const RPN &other) {
	if (DEBUG) {
		std::cout << "RPN Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		this->_stack = other._stack;
	}
	return *this;
}

// ----Destructor
RPN::~RPN() {
	if (DEBUG) {
		std::cout << "RPN destructor called" << std::endl;
	}
}


// ----- Methods ------
bool RPN::parsing(std::string str) {
	std::istringstream ss(str);
	std::string token;

	while(ss >> token) {
		std::cout << token << std::endl;
		if (!validateToken(token)) {
			std::cout << ERROR_PAR << std::endl;
			return false;
		}
	}

	return true;
}

bool RPN::validateToken(std::string& token) {
	size_t pos = token.find_first_of("+-*/");
	if (pos != std::string::npos) {
		return true;
	}
	for (size_t i = 0; i < token.size(); i++)
	{
		if (!std::isdigit(token[i])) {
			return false;
		}
	}
	return true;
}

