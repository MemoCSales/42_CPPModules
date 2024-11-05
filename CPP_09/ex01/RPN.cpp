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
		if (!solving(token)) {
			return false;
		}
	}
	// while (!_stack.empty()) {
	// 	std::cout << _stack.top() << " ";
	// 	_stack.pop();
	// }
	// return solving(str);
	return true;
}

bool RPN::isNumberInRange(const std::string& str) {
	long number = std::atoi(str.c_str());

	if (number >= 0 && number < 10)
		return true;
	return false;
}

bool RPN::isValidOperator(const std::string& token) {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isValidNumber(const std::string& token) {
	for (size_t i = 0; i < token.size(); i++)
	{
		if (!std::isdigit(token[i])) {
			return false;
		}
	}
	return true;
}

bool RPN::validateToken(const std::string& token) {
	if (isNumberInRange(token) && isValidNumber(token)) {
		return true;
	}
	if (isValidOperator(token)) {
		return true;
	}
	return false;
}

bool RPN::solving(std::string str) {
	if (isValidNumber(str)) {
		int number = std::atoi(str.c_str());
		_stack.push(number);
		std::cout << "Number added to stack -> " << number << std::endl;
	}
	if (isValidOperator(str)) {
		for (size_t i = 0; i < 2; i++) {
			_stack.pop();
		}
		
	}
	return true;
}