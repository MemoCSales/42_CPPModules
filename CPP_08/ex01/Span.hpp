#ifndef Span_HPP
# define Span_HPP
# include <iostream>
# include <vector>

# define DEBUG 0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT	"\033[0m"

template <typename T>
class Span {
	private:
		unsigned int _N;
		std::vector<T> _numbers;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		// Method
		void addNumber(int value); 
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
template <typename T>
Span<T>::Span(unsigned int N) : _N(N), _numbers(N) {
	if (DEBUG) {
		std::cout << "Span parameter constructor called" << std::endl;
	}
}

// Copy Constructor
template <typename T>
Span<T>::Span(const Span &other) {
	if (DEBUG) {
		std::cout << "Span copy constructor called" << std::endl;
	}
	this->_N = other._N;
	for (std::vector<int>::iterator it = _numbers.begin(); it != _numbers.end(); it++) {
		this->_numbers.at(it) = other._numbers.at(it);
	}
}

// Assignment Operator
template <typename T>
Span<T> &Span<T>::operator=(const Span &other) {
	if (DEBUG) {
		std::cout << "Span Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		_numbers.clear();
		this->_N = other._N;
		for (std::vector<int>::iterator it = _numbers.begin(); it != _numbers.end(); it++) {
			this->_numbers.at(it) = other._numbers.at(it);
		}
	}
	return *this;
}

// ----Destructor
template <typename T>
Span<T>::~Span() {
	if (DEBUG) {
		std::cout << "Span destructor called" << std::endl;
	}
}


// Methods
template <typename T>
void Span<T>::addNumber(int value) {
	if (_numbers.size() != _N) {
		_numbers.push_back(value);
	} else {
		throw MaximumCapacity();
	}
}
