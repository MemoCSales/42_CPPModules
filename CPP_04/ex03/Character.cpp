#include "Character.hpp"

// ++++Constructor
Character::Character(std::string inputName) : ICharacter(), name(inputName) {
	if (DEBUG) {
		std::cout << "Character parameter constructor called" << std::endl;
	}
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}


// Copy Constructor
Character::Character(const Character &other) : ICharacter(), name(other.name) {
	if (DEBUG) {
		std::cout << "Character copy constructor called" << std::endl;
	}
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL) {
			
		}
	}
	
}

// Assignment Operator
Character &Character::operator=(const Character &other) {
	if (DEBUG) {
		std::cout << "Character assignment operator called" << std::endl;
	}
}

// ----Destructor
Character::~Character() {
	if (DEBUG) {
		std::cout << "Character destructor called" << std::endl;
	}
}

// Getters
std::string const & Character::getName() const {
	return (name);
}

