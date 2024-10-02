#include "Intern.hpp"

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
AForm* Intern::createShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formType, const std::string &target) {
	// try
	// {
		myPointerToFunction functionPointer[] = {
			&Intern::createShrubberyCreationForm,
			&Intern::createRobotomyRequestForm,
			&Intern::createPresidentialPardonForm};
		std::string formTypes[] = {"shrubbery creation",
								"robotomy request",
								"presidential pardon"};
		
		for (size_t i = 0; i < sizeof(formTypes) / sizeof(std::string); i++)
		{
			if (formType == formTypes[i]) {
				std::cout << "Intern creates " << MAGENT << formType << DEFAULT << std::endl;
				return (this->*functionPointer[i]) (target);
			}
			
		}
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	
	// std::cerr << RED << "Error: " << DEFAULT << WHITE << "Form type not recognized" << DEFAULT << std::endl;
	// throw FormNotValid();
	return NULL;
}
