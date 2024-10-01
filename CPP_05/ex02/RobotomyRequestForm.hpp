#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP
# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _targetFile;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string targetFile);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
		// Method
		void execute(Bureaucrat const& executor) const;
};

#endif
