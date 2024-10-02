#ifndef Intern_HPP
# define Intern_HPP
# include <iostream>
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


class Intern {
	public:
		Intern(void);
		// Intern("Parameter Constructor");
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		// Methods
		AForm* createShrubberyCreationForm(std::string &target);
		AForm* createRobotomyRequestForm(std::string &target);
		AForm* createPresidentialPardonForm(std::string &target);
		AForm* makeForm(std::string formType, std::string target);
};

#endif

// #include "Intern.hpp"

typedef AForm* (Intern::*myPointerToFunction) (std::string &target);

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
	(void)other;
}

// Assignment Operator
Intern &Intern::operator=(const Intern &other) {
	if (DEBUG) {
		std::cout << "Intern Assignment Operator called" << std::endl;
	}
	(void)other;
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
AForm* Intern::createShrubberyCreationForm(std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formType, std::string target) {
	myPointerToFunction functionPointer[] = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm};
	std::string formTypes[] = {"shrubbery sreation",
							"robotomy request",
							"presidential pardon"};
	
	for (size_t i = 0; i < sizeof(formTypes) / sizeof(std::string); i++)
	{
		if (formType == formTypes[i]) {
			std::cout << "Intern creates " << MAGENT << formType << DEFAULT << std::endl;
			return (this->*functionPointer[i]) (target);
		}
		
	}
	std::cerr << RED << "Error: " << DEFAULT << WHITE << "Form type not recognized" << DEFAULT << std::endl;
	return NULL;
	
}
