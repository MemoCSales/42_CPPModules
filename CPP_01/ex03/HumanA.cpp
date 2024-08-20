#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string _name, Weapon& _type) : name(_name), type(_type) {	
	if (DEBUG)
		std::cout << "Parameter constructor called in HumanA class" << std::endl;
}

//Destructor
HumanA::~HumanA()
{
	if (DEBUG)
		std::cout << "Default deconstructor called in HumanA class" << std::endl;
}


//Attack method
void	HumanA::attack() {
	std::cout << GREEN << name << DEFAULT << " attacks with their " << RED << type.getType() << DEFAULT << std::endl;
}