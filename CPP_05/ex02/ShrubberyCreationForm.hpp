#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP
# include <iostream>

# define DEBUG 0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT		"\033[0m"

class ShrubberyCreationForm {
	private:
	
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm("Parameter Constructor");
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
};

#endif

#include "ShrubberyCreationForm.hpp"

// ++++Constructor
ShrubberyCreationForm::ShrubberyCreationForm(void) {
	if (DEBUG) {
		std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	}
}

// ++++Constructor
ShrubberyCreationForm::ShrubberyCreationForm("Parameters") {
	if (DEBUG) {
		std::cout << "ShrubberyCreationForm parameter constructor called" << std::endl;
	}
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : "_variable(other._variable)"{
	if (DEBUG) {
		std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	}
}

// Assignment Operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (DEBUG) {
		std::cout << "ShrubberyCreationForm Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		// Copy data from other to this
	}
	return *this;
}

// ----Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	if (DEBUG) {
		std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	}
}
