#include "MutantStack.hpp"

// ++++Constructor
template <typename T>
MutantStack<T>::MutantStack(void) {
	if (DEBUG) {
		std::cout << "MutantStack default constructor called" << std::endl;
	}
}

// Copy Constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) {
	if (DEBUG) {
		std::cout << "MutantStack copy constructor called" << std::endl;
	}
	*this = other;
}

// Assignment Operator
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other) {
	if (DEBUG) {
		std::cout << "MutantStack Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		this->std::stack<T> = other.std::stack<T>;
	}
	return *this;
}

// ----Destructor
template <typename T>
MutantStack<T>::~MutantStack() {
	if (DEBUG) {
		std::cout << "MutantStack destructor called" << std::endl;
	}
}
