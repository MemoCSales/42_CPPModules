#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_formName;
	bool 				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;
public:
	AForm();
	AForm(const std::string formName, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	~AForm();
	// Getters
	std::string getFormName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	// Methods
	void				beSigned(Bureaucrat& bureaucrat);
	virtual void		execute(Bureaucrat const& bureaucrat) const = 0;
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
				return "Error: AForm grade out of bounds. Must be between 1 and 150. Please check!";
			}
	};
	class FormIsNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Error: Form is not signed yet";
			}
	};
};

std::ostream &operator<<(std::ostream &o, const AForm &form);


#endif
