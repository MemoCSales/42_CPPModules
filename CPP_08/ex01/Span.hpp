#ifndef Span_HPP
# define Span_HPP
# include <iostream>
# include <vector>

# define DEBUG 1

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT	"\033[0m"

class Span {
	private:
		unsigned int _N;
		std::vector<int> _numbers;
	public:
		// Span(void);
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		// Method
		void addNumber(int value); 
		void printNumbers() const;
		// Exceptions
		class MaximumCapacity : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Vector has reached its maximum capacity");
			}
		};
};

#endif

// #include "Span.hpp"

// ++++Constructor

// Span::Span() : _N(0), _numbers(0) {
// 	if (DEBUG) {
// 		std::cout << "Span parameter constructor called" << std::endl;
// 	}
// }


Span::Span(unsigned int N) : _N(N), _numbers(0) {
	if (DEBUG) {
		std::cout << "Span parameter constructor called" << std::endl;
	}
}

// Copy Constructor

Span::Span(const Span &other) {
	if (DEBUG) {
		std::cout << "Span copy constructor called" << std::endl;
	}
	this->_N = other._N;
	this->_numbers = other._numbers;
}

// Assignment Operator

Span &Span::operator=(const Span &other) {
	if (DEBUG) {
		std::cout << "Span Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		this->_N = other._N;
		this->_numbers = other._numbers;
	}
	return *this;
}

// ----Destructor

Span::~Span() {
	if (DEBUG) {
		std::cout << "Span destructor called" << std::endl;
	}
}


// Methods
void Span::addNumber(int value) {
	if (_numbers.size() != _N) {
		_numbers.push_back(value);
	} else {
		throw MaximumCapacity();
	}
}

void Span::printNumbers() const {
	for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); it++)
	{
		std::cout << "Numbers: " << *it << std::endl;
	}
	
}
