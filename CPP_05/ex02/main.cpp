#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
		std::cout << GREEN << "---- STARTING TESTING ----" <<  DEFAULT << std::endl;
	{
		std::cout << BLUE << "\n---- ShrubberyCreationForm Test: ----" <<  DEFAULT << std::endl;
		try {
			Bureaucrat john("John", 10);

			// Creating a form
			ShrubberyCreationForm form("file");

			std::cout << john << std::endl;
			std::cout << form << std::endl;
			// John tries to sign the form
			john.signForm(form);

			// form.execute(john);
			john.executeform(form);

		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << BLUE << "\n---- RobotomyRequestForm Test: ----" <<  DEFAULT << std::endl;
		try {
			Bureaucrat john("John", 10);

			// Creating a form
			RobotomyRequestForm form("file");

			std::cout << john << std::endl;
			std::cout << form << std::endl;
			// John tries to sign the form
			john.signForm(form);

			// form.execute(john);
			john.executeform(form);

		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
