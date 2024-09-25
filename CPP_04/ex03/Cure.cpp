#include "Cure.hpp"


// ++++Constructor
Cure::Cure(void) : AMateria("cure") {
	if (DEBUG) {
		std::cout << "Cure default constructor called" << std::endl;
	}
}

// ----Destructor
Cure::~Cure() {
	if (DEBUG) {
		std::cout << "Cure default destructor called" << std::endl;
	}
}

// Methods
AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << GREEN << "* heals " << target << "'s wounds *" << DEFAULT << std::endl;
}
