#include "AForm.hpp"

// ++++Constructor
AForm::AForm() :
	_formName(""), _isSigned(false), _gradeToSign(0), _gradeToExecute(0){
	if (DEBUG) { 
		std::cout << "AForm default constructor called" << std::endl;
	}
}
AForm::AForm(const std::string formName, const int gradeToSign, const int gradeToExecute) :
	_formName(formName), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (DEBUG) { 
		std::cout << "AForm parameter constructor called" << std::endl;
	}
	if (gradeToSign < 1)
		throw FormGradeException();
	if (gradeToSign > 150)
		throw FormGradeException();
}

// Copy Constructor
AForm::AForm(const AForm &other) : 
 _formName(other._formName), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	if (DEBUG) { 
		std::cout << "AForm copy constructor called" << std::endl;
	}
 }

// Assignment Operator
AForm &AForm::operator=(const AForm &other) {
	if (DEBUG) { 
		std::cout << "AForm Assignment Operator" << std::endl;
	}
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}


// ----Destructor
AForm::~AForm() {
	if (DEBUG) { 
		std::cout << "AForm Destructor called" << std::endl;
	}
}

// Getters
std::string AForm::getFormName() const {
	return _formName;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

// Methods
/*
	This function changes the form’s signed status based on a 
	Bureaucrat object that attempts to sign it.
*/
void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= getGradeToSign())
		_isSigned = true;
	else
		throw GradeTooLowException();
}

// << Overload Operator
std::ostream &operator<<(std::ostream &o, const AForm &form) {
	o << "AForm: " << CYAN << form.getFormName() << DEFAULT << "\n";
	o << "Sign Status: " << WHITE << form.getIsSigned() << DEFAULT << "\n";
	o << "Required Grade to Sign: " << GREEN << form.getGradeToSign() << DEFAULT << "\n";
	o << "Required Grade to Execute: " << MAGENT << form.getGradeToExecute() << DEFAULT << std::endl; 
	return (o);
}
