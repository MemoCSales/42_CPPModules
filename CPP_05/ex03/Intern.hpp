#ifndef Intern_HPP
# define Intern_HPP
# include <iostream>
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern(void);
		// Intern("Parameter Constructor");
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		// Methods
		AForm* createShrubberyCreationForm(std::string &target);
		AForm* createRobotomyRequestForm(std::string &target);
		AForm* createPresidentialPardonForm(std::string &target);
		AForm* makeForm(std::string formType, std::string target);
};

#endif
