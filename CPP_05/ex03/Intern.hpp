#ifndef Intern_HPP
# define Intern_HPP
# include <iostream>
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	private:
		AForm* createShrubberyCreationForm(const std::string &target);
		AForm* createRobotomyRequestForm(const std::string &target);
		AForm* createPresidentialPardonForm(const std::string &target);

	public:
		Intern(void);
		// Intern("Parameter Constructor");
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		// Methods
		AForm* makeForm(const std::string &formType, const std::string &target);
		// Exceptions
		class FormNotValid : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: Form type not recognized";
				}
		};
};

#endif
