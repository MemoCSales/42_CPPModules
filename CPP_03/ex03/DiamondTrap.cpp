#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	if (DEBUG)
		std::cout << "DiamondTrap default constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(std::string _name)
	: ClapTrap(_name + "_clap_name"), FragTrap(_name), ScavTrap(_name),  name(_name) {
	if (DEBUG)
		std::cout << "DiamondTrap parameter constructor called" << std::endl;

	this->setAttackDamage(FragTrap::getAttackDamage());		// DiamondTrap will inherit attackDamage from FragTrap
	this->setHitPoints(FragTrap::getHitPoints());			// DiamondTrap will inherit hitPoints from FragTrap
	this->setEnergyPoints(ScavTrap::getEnergyPoints());		// DiamondTrap will inherit energyPoints from ScavTrap

	std::cout << "DiamondTrap Attack Damage: " << this->getAttackDamage() << std::endl;
	std::cout << "FragTrap Attack Damage: " << FragTrap::getAttackDamage() << std::endl;
	std::cout << "DiamondTrap Energy Points: " << this->getEnergyPoints() << std::endl;
	std::cout << "ScavTrap Energy Points: " << ScavTrap::getEnergyPoints() << std::endl;
}


// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other),  name(other.name) {
	if (DEBUG)
		std::cout << "Diamond copy constructor called" << std::endl;
}


// Assignment operator overload
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (DEBUG)
		std::cout << "DiamondTrap Operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		name = other.name;
	}
	return (*this);
}


// Destructor
DiamondTrap::~DiamondTrap() {
	if (DEBUG)
		std::cout << "DiamondTrap destructor called" << std::endl;
}


// Method function whoAmI
void DiamondTrap::whoAmI() {
	std::cout << "I am " << GREEN << this->name << DEFAULT \
	" and my ClapTrap name is " << YELLOW << ClapTrap::getName() << DEFAULT << std::endl;
}
