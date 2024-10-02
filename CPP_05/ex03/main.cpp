#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
		std::cout << GREEN << "---- STARTING TESTING ----" <<  DEFAULT << std::endl;
	// {
	// 	std::cout << BLUE << "\n---- ShrubberyCreationForm Test: ----" <<  DEFAULT << std::endl;
	// 	try {
	// 		Bureaucrat john("John", 10);

	// 		// Creating a form
	// 		ShrubberyCreationForm form("file");

	// 		std::cout << john << std::endl;
	// 		std::cout << form << std::endl;
	// 		// John tries to sign the form
	// 		john.signForm(form);

	// 		// form.execute(john);
	// 		john.executeform(form);

	// 	}
	// 	catch (const std::exception& e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	std::cout << BLUE << "\n---- RobotomyRequestForm Test: ----" <<  DEFAULT << std::endl;
	// 	try {
	// 		Bureaucrat john("John", 10);

	// 		// Creating a form
	// 		RobotomyRequestForm form("file");

	// 		std::cout << john << std::endl;
	// 		std::cout << form << std::endl;
	// 		// John tries to sign the form
	// 		john.signForm(form);

	// 		// form.execute(john);
	// 		john.executeform(form);

	// 	}
	// 	catch (const std::exception& e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	std::cout << BLUE << "\n---- PresidentialPardonForm Test: ----" <<  DEFAULT << std::endl;
	// 	try {
	// 		Bureaucrat john("John", 10);
	// 		Bureaucrat president("President", 1);

	// 		// Creating a form
	// 		PresidentialPardonForm form("Karen");

	// 		std::cout << john << std::endl;
	// 		std::cout << form << std::endl;
	// 		// John tries to sign the form
	// 		john.signForm(form);

	// 		// form.execute(john);
	// 		john.executeform(form);
	// 		president.executeform(form);

	// 	}
	// 	catch (const std::exception& e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	{
		std::cout << BLUE << "\n---- Intern Test: ----" <<  DEFAULT << std::endl;
			Intern	intern;
			AForm*	rrf;

			rrf = intern.makeForm("robotomy request", "Bender");
			if (rrf) {
				std::cout << *rrf << std::endl;
			}

			AForm* form2 = intern.makeForm("presidential pardon", "Zaphod");
			if (form2) {
				std::cout << *form2 << std::endl;
			}

			AForm* invalidForm = intern.makeForm("invalid form", "john");

			Bureaucrat president("President", 1);
			std::cout << president << std::endl;

			president.signForm(*form2);

			form2->execute(president);
			
			delete rrf;
			delete form2;
			delete invalidForm;
	}
	return 0;
}
