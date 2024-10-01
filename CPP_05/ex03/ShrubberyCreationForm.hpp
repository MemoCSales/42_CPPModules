#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP
# include <iostream>
# include <fstream>
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

class ShrubberyCreationForm: public AForm 
{
	private:
		std::string _targetFile;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string targetFile);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		// Method
		void execute(Bureaucrat const& bureaucrat) const;
};

#endif
