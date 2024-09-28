#include "Form.hpp"

// ++++Constructor
Form::Form() :
	_formName(""), _isSigned(false), _gradeToSign(0), _gradeToExecute(0){
	if (DEBUG) { 
		std::cout << "Form default constructor called" << std::endl;
	}
}
Form::Form(const std::string formName, const int gradeToSign, const int gradeToExecute) :
	_formName(formName), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (DEBUG) { 
		std::cout << "Form parameter constructor called" << std::endl;
	}
	if (gradeToSign < 1)
		throw FormGradeException();
	if (gradeToSign > 150)
		throw FormGradeException();
}

// Copy Constructor
Form::Form(const Form &other) : 
 _formName(other._formName), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	if (DEBUG) { 
		std::cout << "Form copy constructor called" << std::endl;
	}
 }

// Assignment Operator
Form &Form::operator=(const Form &other) {
	if (DEBUG) { 
		std::cout << "Form Assignment Operator" << std::endl;
	}
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}


// ----Destructor
Form::~Form() {
	if (DEBUG) { 
		std::cout << "Form Destructor called" << std::endl;
	}
}

// Getters
std::string Form::getFormName() const {
	return _formName;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

// Methods
/*
	This function changes the form’s signed status based on a 
	Bureaucrat object that attempts to sign it.
*/
void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= getGradeToSign())
		_isSigned = true;
	else
		throw GradeTooLowException();
}

// << Overload Operator
std::ostream &operator<<(std::ostream &o, const Form &form) {
	o << "Form: " << BLUE << form.getFormName() << DEFAULT << ",";
	o << "Sign Status: " << WHITE << form.getIsSigned() << DEFAULT << ",";
	o << "Required Grade to Sign: " << GREEN << form.getGradeToSign() << DEFAULT << ",";
	o << "Required Grade to Execute: " << MAGENT << form.getGradeToExecute() << DEFAULT << "." << std::endl; 
	return (o);
}
