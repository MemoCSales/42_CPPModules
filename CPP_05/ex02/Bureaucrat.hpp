#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "Form.hpp"


# define DEBUG 0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE	 	"\033[1;37m"
# define DEFAULT	"\033[0m"

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string _name, int _grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	// Getters
	std::string getName() const;
	int 		getGrade() const;
	// Methods
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form);
	// Exceptions
	class GradeTooHighException :  public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error: Bureaucrat grade is too High");
			}
	};
	class GradeTooLowException :  public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Error: Bureaucrat grade is too Low");
			}
	};
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif
