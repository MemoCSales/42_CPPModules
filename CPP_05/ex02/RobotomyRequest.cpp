#ifndef RobotomyRequest_HPP
# define RobotomyRequest_HPP
# include <iostream>
# include "AForm.hpp"

# define DEBUG 0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT		"\033[0m"

class RobotomyRequest : public AForm
{
	private:
		std::string _targetFile;
	public:
		RobotomyRequest(void);
		RobotomyRequest(std::string targetFile);
		RobotomyRequest(const RobotomyRequest &other);
		RobotomyRequest &operator=(const RobotomyRequest &other);
		~RobotomyRequest();
		// Method
		void execute(Bureaucrat const& executor) const;
};

#endif

// #include "RobotomyRequest.hpp"

// ++++Constructor
RobotomyRequest::RobotomyRequest(void) {
	if (DEBUG) {
		std::cout << "RobotomyRequest default constructor called" << std::endl;
	}
}

// ++++Constructor
RobotomyRequest::RobotomyRequest(std::string targetFile) :
	AForm("Robotomy Request Form", 72, 45), _targetFile(targetFile) {
	if (DEBUG) {
		std::cout << "RobotomyRequest parameter constructor called" << std::endl;
	}
}

// Copy Constructor
RobotomyRequest::RobotomyRequest(const RobotomyRequest &other) : 
	AForm(other), _targetFile(other._targetFile) {
	if (DEBUG) {
		std::cout << "RobotomyRequest copy constructor called" << std::endl;
	}
}

// Assignment Operator
RobotomyRequest &RobotomyRequest::operator=(const RobotomyRequest &other) {
	if (DEBUG) {
		std::cout << "RobotomyRequest Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		AForm::operator=(other);
		_targetFile = other._targetFile;
	}
	return *this;
}

// ----Destructor
RobotomyRequest::~RobotomyRequest() {
	if (DEBUG) {
		std::cout << "RobotomyRequest destructor called" << std::endl;
	}
}

// Method
void RobotomyRequest::execute(Bureaucrat const& executor) const {
	if (!this->getIsSigned())
		throw FormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
}
