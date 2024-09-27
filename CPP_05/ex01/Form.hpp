#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _formName;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	Form();
	Form(const std::string formName, const int gradeToSign, const int gradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	// Getters
	std::string getFormName() const;
	bool		getIsSigned() const;
	const int	getGradeToSign() const;
	const int	getGradeToExecute() const;
	// Methods
	
	// Exceptions
	// Exceptions
	class GradeTooHighException :  public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error: Form grade is too High");
			}
	};
	class GradeTooLowException :  public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error: Form grade is too Low");
			}
	};
};

std::ostream &operator<<(std::ostream &o, const Form &form);

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

const int Form::getGradeToSign() const {
	return _gradeToSign;
}

const int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

// std::ostream &operator<<(std::ostream &o, const Form &form) {
// 	o << 
// }

#endif