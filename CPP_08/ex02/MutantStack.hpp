#pragma once
# include <iostream>
# include <stack>

# define DEBUG 0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT	"\033[0m"

class MutantStack {
	private:
	
	public:
		MutantStack(void);
		MutantStack("Parameter Constructor");
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();
};

#endif

#include "MutantStack.hpp"

// ++++Constructor
MutantStack::MutantStack(void) {
	if (DEBUG) {
		std::cout << "MutantStack default constructor called" << std::endl;
	}
}

// ++++Constructor
MutantStack::MutantStack("Parameters") {
	if (DEBUG) {
		std::cout << "MutantStack parameter constructor called" << std::endl;
	}
}

// Copy Constructor
MutantStack::MutantStack(const MutantStack &other) : "_variable(other._variable)"{
	if (DEBUG) {
		std::cout << "MutantStack copy constructor called" << std::endl;
	}
}

// Assignment Operator
MutantStack &MutantStack::operator=(const MutantStack &other) {
	if (DEBUG) {
		std::cout << "MutantStack Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		// Copy data from other to this
	}
	return *this;
}

// ----Destructor
MutantStack::~MutantStack() {
	if (DEBUG) {
		std::cout << "MutantStack destructor called" << std::endl;
	}
}
