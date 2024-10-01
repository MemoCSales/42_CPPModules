#include "ShrubberyCreationForm.hpp"

// ++++Constructor
ShrubberyCreationForm::ShrubberyCreationForm(void) {
	if (DEBUG) {
		std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	}
}

// ++++Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string targetFile) : 
	AForm("Shrubbery Creation Form", 145, 137), _targetFile(targetFile) {
	if (DEBUG) {
		std::cout << "ShrubberyCreationForm parameter constructor called" << std::endl;
	}
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : 
	AForm(other), _targetFile(other._targetFile) {
	if (DEBUG) {
		std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	}
}

// Assignment Operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (DEBUG) {
		std::cout << "ShrubberyCreationForm Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		AForm::operator=(other);
		_targetFile = other._targetFile;
	}
	return *this;
}

// ----Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	if (DEBUG) {
		std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	}
}


// Method
void ShrubberyCreationForm::execute(Bureaucrat const& bureaucrat) const {
	if (!this->getIsSigned())
		throw FormIsNotSignedException();
	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();

	std::ofstream outputFile((_targetFile + "_shrubbery").c_str());
	if (!outputFile.is_open())
		throw std::runtime_error("Error: Could not open file");

	outputFile << "       _-_\n";
	outputFile << "    /~~   ~~\\\n";
	outputFile << " /~~         ~~\\\n";
	outputFile << "{               }\n";
	outputFile << " \\  _-     -_  /\n";
	outputFile << "   ~  \\ //  ~\n";
	outputFile << "_- -   | | _- _\n";
	outputFile << "  _ -  | |   -_\n";
	outputFile << "      // \\\n";
	outputFile.close();
}
