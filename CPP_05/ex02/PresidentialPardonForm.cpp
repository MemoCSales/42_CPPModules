#include "PresidentialPardonForm.hpp"

// ++++Constructor
PresidentialPardonForm::PresidentialPardonForm(void) : 
	AForm("Default Form", 0, 0), _target("Default target") {
	if (DEBUG) {
		std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	}
}

// ++++Constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon Request", 25, 5), _target(target) {
	if (DEBUG) {
		std::cout << "PresidentialPardonForm parameter constructor called" << std::endl;
	}
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : 
	AForm(other), _target(other._target) {
	if (DEBUG) {
		std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	}

}

// Assignment Operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (DEBUG) {
		std::cout << "PresidentialPardonForm Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// ----Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
	if (DEBUG) {
		std::cout << "PresidentialPardonForm destructor called" << std::endl;
	}
}

// Method
void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!this->getIsSigned())
		throw FormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	
	std::cout << WHITE << _target << DEFAULT << GREEN << " has been pardoned by Zaphod Beeblebrox." << DEFAULT << std::endl;
}
