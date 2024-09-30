#include "Bureaucrat.hpp"

int main() {
		std::cout << GREEN << "---- STARTING TESTING ----" <<  DEFAULT << std::endl;
	{
		std::cout << BLUE << "\n---- John Test: ----" <<  DEFAULT << std::endl;
		try {
			Bureaucrat john("John", 40);

			// Creating a form
			Form leaveRequest("Leave Request", 50, 20);

			// John tries to sign the form
			john.signForm(leaveRequest);

			// new form: form_name, gradeToSign, gradeToExecute
			Form budgetApproval("Budget Approval", 30, 10);

			john.signForm(budgetApproval);
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << BLUE << "\n---- Alice Test: ----" <<  DEFAULT << std::endl;
		try
		{
			Bureaucrat alice("Alice", 50);
			Form contract("Contract", 50, 20);

			alice.signForm(contract);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << BLUE << "\n---- Intern Test: ----" <<  DEFAULT << std::endl;
		try
		{
			Bureaucrat intern("Intern", 150);
			Form taxForm("Tax Form", 100, 50);
			// taxForm.beSigned(intern);
			std::cout << intern << std::endl;
			std::cout << taxForm << std::endl;

			intern.signForm(taxForm);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << BLUE << "\n---- Invalid Form Test: ----" <<  DEFAULT << std::endl;
		try
		{
			Form invalidForm("Invalid Form", 0, 10);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		
	}
	return 0;
}
