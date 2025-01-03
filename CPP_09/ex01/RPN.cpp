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
		// if (DEBUG) std::cout << token << std::endl;
		bool isLast = ss.peek() == EOF;

		if (!validateToken(token)) {
			std::cout << ERROR_PAR << std::endl;
			return false;
		}
		if (!solving(token, isLast)) {
			return false;
		}
	}
	return true;
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
	if (isValidNumber(token)) {
		return true;
	}
	if (isValidOperator(token)) {
		return true;
	}
	return false;
}

int RPN::operation(int a, int b, std::string& sign) {
	int result = 0;
	switch (sign[0])
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		if (b == 0) {
			throw std::runtime_error("Error: Division by zero is undefined.");
		}
		result = a / b;
		break;
	
	default:
		throw std::runtime_error("Invalid operator");
	}
	return result;
}

bool RPN::solving(std::string str, bool isLast) {
	try
	{
		if (isValidNumber(str)) {
			int number = std::atoi(str.c_str());
			_stack.push(number);
			if (DEBUG) std::cout << "Number added to stack -> " << number << std::endl;
		} else if (isValidOperator(str)) {
			if (_stack.size() < 2) {
				std::cerr << "Error: Not enough arguments." << std::endl;
				return false;
			}
			if (DEBUG) std::cout << "Operator = " << str << std::endl;
				int a = _stack.top();
				if (DEBUG) std::cout << "a = " << a << std::endl;
				_stack.pop();
				int b = _stack.top();
				if (DEBUG) std::cout << "b = " << b << std::endl;
				_stack.pop();
			int result = operation(b, a, str);
			_stack.push(result);
			if (DEBUG) std::cout << "Result = " << result << std::endl;
			if (DEBUG) std::cout << "Result added to stack -> " << result << std::endl;
		}
		if (isLast) {
			if (!_stack.empty()) {
				std::cout << _stack.top() << std::endl;
			} else {
				throw std::runtime_error("Stack is empty");
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return true;
}

bool argsValidation(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << ERROR_MESSAGE << std::endl;
		return false;
	}
	std::string str = argv[1];
	if (str.empty()) {
		std::cerr << "Error" << std::endl;
		return false;
	}
	return true;
}