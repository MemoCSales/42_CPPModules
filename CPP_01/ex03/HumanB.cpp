#include "HumanB.hpp"

//Constructor with parameters
HumanB::HumanB(std::string _name) : name(_name), type(NULL) {
	if (DEBUG)
		std::cout << "Default constructor called in HumanB class" << std::endl;
}

//Destructor
HumanB::~HumanB()
{
	if (DEBUG)
		std::cout << "Default deconstructor called in HumanB class" << std::endl;
}

//Attack method
void	HumanB::attack() {
	std::cout << YELLOW << name << DEFAULT << " attacks with their " << RED << type->getType() << DEFAULT << std::endl;
	// delete type;
}

//Setter method
void    HumanB::setWeapon(Weapon& _type) {
	type = &_type;
}