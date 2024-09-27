#include "Bureaucrat.hpp"

int main() {
		std::cout << GREEN << "---- STARTING TESTING ----" <<  DEFAULT << std::endl;
	{
		std::cout << YELLOW << "---- TEST 1: BUREAUCRAT CREATION & EXCEPTION ----" <<  DEFAULT << std::endl;
		int grade = 22;
		try	{
			Bureaucrat temp("Temp", grade);
			std::cout << temp << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << YELLOW << "---- TEST 2: INCREASING & DECREASING GRADES ----" <<  DEFAULT << std::endl;
		int grade = 1;
		try	{
			Bureaucrat bob("Bob", grade);
			std::cout << bob << std::endl;
			bob.incrementGrade();
			std::cout << bob << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cerr << e.what() << std::endl;
		}

		try	{
			Bureaucrat karen("Karen", 140);
			std::cout << karen << std::endl;
			for (int i = 0; i < 100; i++) {
				karen.decrementGrade();
				std::cout << "i: " << i << " -> ";
				std::cout << karen << std::endl;
			}
			
		}
		catch(const Bureaucrat::GradeTooHighException &e) {
			std::cerr << e.what() << std::endl;
		} catch (const Bureaucrat::GradeTooLowException &e) {
			std::cerr << e.what() << std::endl;
		}
		
	}
	return 0;
}
