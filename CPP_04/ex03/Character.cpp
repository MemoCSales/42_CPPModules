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
	for (int i = 0; i < 4; i++)	{
		if (other.inventory[i] != NULL) {
			this->inventory[i] = other.inventory[i]->clone();
		} else {
			this->inventory[i] = NULL;
		}
	}
	
}

// Assignment Operator
Character &Character::operator=(const Character &other) {
	if (DEBUG) {
		std::cout << "Character assignment operator called" << std::endl;
	}
	if (this != &other) {
		for (int i = 0; i < 4; i++)	{
			if (inventory[i] != NULL) {
				delete inventory[i];
				inventory[i] = NULL;
			}
		}
		this->name = other.name;
		for (int i = 0; i < 4; i++)	{
			if (other.inventory[i] != NULL) {
				this->inventory[i] = other.inventory[i]->clone();
			} else {
				this->inventory[i] = NULL;
			}
		}
	}
	return (*this);
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

// ****Methods
void Character::equip(AMateria* m) {
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL) {
			inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
		return ;
	// unequippedMateria[idx] = inventory[idx];
	delete inventory[idx]; //check it later
	inventory[idx] == NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
		return ;
	
	inventory[idx]->use(target);		// Call the use method from the corresponding AMateria
}
