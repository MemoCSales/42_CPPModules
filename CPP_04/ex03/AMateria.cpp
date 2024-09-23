#include "AMateria.hpp"

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

// Methods
void AMateria::use(ICharacter& target) {
	std::cout << WHITE << "* shoots a random materia at " << target << " *"<< DEFAULT << std::endl;
}
