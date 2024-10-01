#ifndef Intern_HPP
# define Intern_HPP
# include <iostream>
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern(void);
		// Intern("Parameter Constructor");
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		// Methods
		AForm* createShrubberyCreationForm(std::string &target);
		AForm* makeForm(std::string formType, std::string target);
};

#endif

// #include "Intern.hpp"

typedef AForm* (Intern::*myPointerToFunction) (const std::string &target);

// ++++Constructor
Intern::Intern(void) {
	if (DEBUG) {
		std::cout << "Intern default constructor called" << std::endl;
	}
}

// ++++Constructor
// Intern::Intern("Parameters") {
// 	if (DEBUG) {
// 		std::cout << "Intern parameter constructor called" << std::endl;
// 	}
// }

// Copy Constructor
Intern::Intern(const Intern &other) {
	if (DEBUG) {
		std::cout << "Intern copy constructor called" << std::endl;
	}
}

// Assignment Operator
Intern &Intern::operator=(const Intern &other) {
	if (DEBUG) {
		std::cout << "Intern Assignment Operator called" << std::endl;
	}
	// No attributes to assign
	return *this;
}

// ----Destructor
Intern::~Intern() {
	if (DEBUG) {
		std::cout << "Intern destructor called" << std::endl;
	}
}

// Method
// AForm* Intern::createShrubberyCreationForm(std::string &target) {
// 	return new(ShrubberyCreationForm(target));
// }

// AForm* Intern::makeForm(std::string formType, std::string target) {
// 	myPointerToFunction functionPointer[] = {&ShrubberyCreationForm("home")}
// }
