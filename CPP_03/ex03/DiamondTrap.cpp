#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	if (DEBUG)
		std::cout << "DiamondTrap default constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(std::string _name)
	: ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name), name(_name) {
	if (DEBUG)
		std::cout << "DiamondTrap parameter constructor called" << std::endl;
	this->hitPoints = FragTrap::_hitPoints;
	this->energyPoints = ScavTrap::_energyPoints;
	this->attackDamage = FragTrap::_attackDamage;
}


// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
	if (DEBUG)
		std::cout << "Diamond copy constructor called" << std::endl;
	this->name = other.name;
	this->hitPoints = other.FragTrap::hitPoints;
	this->energyPoints = other.ScavTrap::energyPoints;
	this->attackDamage = other.FragTrap::attackDamage;
}


// Assignment operator overload
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (DEBUG)
		std::cout << "DiamondTrap Operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.FragTrap::hitPoints;
		this->energyPoints = other.ScavTrap::energyPoints;
		this->attackDamage = other.FragTrap::attackDamage;
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

// Getters
std::string	DiamondTrap::getName() const {
	return name;
}
