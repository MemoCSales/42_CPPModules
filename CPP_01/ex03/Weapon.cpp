#include "Weapon.hpp"

//Setters
void    Weapon::setType(const std::string &_type) {
	type = _type;
}

//Getter
const std::string& Weapon::getType() const {
	return type;
}

//Constructors
Weapon::Weapon()
{
	if (DEBUG)
		std::cout << "Default constructor called in Weapon class" << std::endl;
}

Weapon::Weapon(std::string _type)
{
	type = _type;
	if (DEBUG)
		std::cout << "Parameter constructor called in Weapon class" << std::endl;
}

Weapon::~Weapon()
{
	if (DEBUG)
		std::cout << "Default deconstructor called in Weapon class" << std::endl;
}
