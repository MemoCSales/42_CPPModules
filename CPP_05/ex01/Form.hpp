#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

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
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	// Methods
	void		beSigned(Bureaucrat& bureaucrat);
	// Exceptions
	class GradeTooHighException :  public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("form requires a bureaucrat with a lower grade.");
			}
	};
	class GradeTooLowException :  public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("form requires a bureaucrat with a higher grade.");
			}
	};
	class FormGradeException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Error: Form grade out of bounds. Must be between 1 and 150. Please check!";
			}
	};
};

std::ostream &operator<<(std::ostream &o, const Form &form);


#endif
