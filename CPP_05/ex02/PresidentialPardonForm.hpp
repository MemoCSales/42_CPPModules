#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm  : public AForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();
		// Method
		void execute(Bureaucrat const& executor) const;
};

#endif

