#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	if (DEBUG)
		std::cout << "DiamondTrap default constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(std::string _name)
	: ClapTrap(_name + "_clap_name"), FragTrap(_name), name(_name) {
	if (DEBUG)
		std::cout << "DiamondTrap parameter constructor called" << std::endl;

	this->setHitPoints(FragTrap::getHitPoints());			// DiamondTrap will inherit hitPoints from FragTrap
	this->setEnergyPoints(ScavTrap::getEnergyPoints());		// DiamondTrap will inherit energyPoints from ScavTrap
	this->setAttackDamage(FragTrap::getAttackDamage());		// DiamondTrap will inherit attackDamage from FragTrap
	// ScavTrap::attack();
}


// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) {
	if (DEBUG)
		std::cout << "Diamond copy constructor called" << std::endl;
	(void)other;
	return ;
}


// Assignment operator overload
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (DEBUG)
		std::cout << "DiamondTrap Operator called" << std::endl;
	(void)other;
	return (*this);
}


// Destructor
DiamondTrap::~DiamondTrap() {
	if (DEBUG)
		std::cout << "DiamondTrap destructor called" << std::endl;
}