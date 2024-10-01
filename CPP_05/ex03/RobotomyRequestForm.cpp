#include "RobotomyRequestForm.hpp"

// ++++Constructor
RobotomyRequestForm::RobotomyRequestForm(void) : 
	AForm("Default Request", 0, 0), _targetFile("Default target file") {
	if (DEBUG) {
		std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	}
}

// ++++Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string targetFile) :
	AForm("Robotomy Request", 72, 45), _targetFile(targetFile) {
	if (DEBUG) {
		std::cout << "RobotomyRequestForm parameter constructor called" << std::endl;
	}
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : 
	AForm(other), _targetFile(other._targetFile) {
	if (DEBUG) {
		std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	}
}

// Assignment Operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (DEBUG) {
		std::cout << "RobotomyRequestForm Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		AForm::operator=(other);
		_targetFile = other._targetFile;
	}
	return *this;
}

// ----Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
	if (DEBUG) {
		std::cout << "RobotomyRequestForm destructor called" << std::endl;
	}
}

// Method
void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!this->getIsSigned())
		throw FormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	
	int result = rand() % 2;
	if (result == 1)
		std::cout << "The " << WHITE << this->getFormName() << DEFAULT << " has been successfully robotomized!" << std::endl;
	else
		std::cerr << "The " << WHITE << this->getFormName() << DEFAULT << " has failed!" << std::endl;
}
