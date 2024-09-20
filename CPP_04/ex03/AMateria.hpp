#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"

# define DEBUG 1

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE	 	"\033[1;37m"
# define DEFAULT	"\033[0m"

class AMateria
{
protected:
	std::string type;
public:
	AMateria(std::string const & type);
	/*something more here*/
	virtual ~AMateria();
	//Getters
	std::string const & getType() const;
	// Methods
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

AMateria::AMateria(std::string const & _type) : type(_type) {
	if (DEBUG)
		std::cout << "AMateria parameter constructor called" << std::endl;
}

AMateria::~AMateria() {
	if (DEBUG)
		std::cout << RED << "AMateria virtual destructor called" << DEFAULT << std::endl;
}

// Getters
std::string const & AMateria::getType() const {
	return type;
}


#endif