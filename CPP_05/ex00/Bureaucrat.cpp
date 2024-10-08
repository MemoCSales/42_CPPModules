#include "Bureaucrat.hpp"

// ++++Constructor
Bureaucrat::Bureaucrat() {
	if (DEBUG) { 
		std::cout << "Bureaucrat parameter constructor called" << std::endl;
	}
}

// ++++Constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (DEBUG) { 
		std::cout << "Bureaucrat parameter constructor called" << std::endl;
	}
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	if (DEBUG) { 
		std::cout << "Bureaucrat copy constructor called" << std::endl;
	}
}

// Assignment Operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (DEBUG) { 
		std::cout << "Bureaucrat Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

// ----Destructor
Bureaucrat::~Bureaucrat() {
	if (DEBUG) { 
		std::cout << "Bureaucrat destructor called" << std::endl;
	}
}

// Getters
std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}


// Methods
void Bureaucrat::incrementGrade() {
	if (DEBUG) { 
		std::cout << "Increment grade method called" << std::endl;
	}
	--_grade;
	if (_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	if (DEBUG) { 
		std::cout << "Decrement grade method called" << std::endl;
	}
	++_grade;
	if (_grade > 150)
		throw GradeTooLowException();
}


std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat) {
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (o);
}
