#include "../ex00/ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	if (DEBUG)
		std::cout << "ScavTrap default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name) {
	if (DEBUG)
		std::cout << "ScavTrap parameter constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (DEBUG)
		std::cout << "Assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}


ScavTrap::~ScavTrap() {
    if (DEBUG)
        std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " <<  YELLOW << getName() << DEFAULT << " is now in Gatekeeper Mode!" << std::endl;
}
