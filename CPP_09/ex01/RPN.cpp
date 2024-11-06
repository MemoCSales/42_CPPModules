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
	int finalResult = 0;

	while(ss >> token) {
		// std::cout << token << std::endl;
		bool isLast = ss.peek() == EOF;

		if (!validateToken(token)) {
			std::cout << ERROR_PAR << std::endl;
			return false;
		}
		if (isLast) {
			finalResult = solving(token, isLast);
		} else {
			if (!solving(token, isLast)) {
				return false;
			}
		}
	}
	std::cout << _stack.top() << std::endl;
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
		result = a / b;
		break;
	
	default:
		std::cout << "Invalid operator" << std::endl;
		break;
	}
	return result;
}

bool RPN::solving(std::string str, bool isLast) {
	if (isValidNumber(str)) {
		int number = std::atoi(str.c_str());
		_stack.push(number);
		// std::cout << "Number added to stack -> " << number << std::endl;
	}
	int a = 0;
	int b = 0;
	int result = 0;

	if (isValidOperator(str)) {
		// std::cout << "Operator = " << str << std::endl;
			a = _stack.top();
			// std::cout << "a = " << a << std::endl;
			_stack.pop();
			b = _stack.top();
			// std::cout << "b = " << b << std::endl;
			_stack.pop();
		result = operation(b, a, str);
		_stack.push(result);
		// std::cout << "Result = " << result << std::endl;
	}
	if (isLast) {
		if (!_stack.empty()) {
			// std::cout << "stack: " << _stack.top() << std::endl;
			return _stack.top();
		} else {
			throw std::runtime_error("Stack is empty");
		}
	}
	return true;
}
