#include "Ice.hpp"

// ++++Constructor
Ice::Ice(void) : AMateria("ice") {
	if (DEBUG) {
		std::cout << "Ice default constructor called" << std::endl;
	}
}


// ----Destructor
Ice::~Ice() {
	if (DEBUG) {
		std::cout << "Ice default destructor called" << std::endl;
	}
}

// Methods

/* It creates a new indepndent object --> deep copy */
/* The return type is being upcasted to the upper class (AMateria). 
	This is safe because Ice is derived from AMateria*/
AMateria* Ice::clone() const {
	Ice* cloneMateria = new Ice();
	return (dynamic_cast<AMateria*>(cloneMateria)); // Upcasting
}

void Ice::use(ICharacter& target) {
	std::cout << BLUE << "* shoots an ice bolt at " << target << " *"<< DEFAULT << std::endl;
}
