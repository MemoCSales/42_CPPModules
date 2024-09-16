#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	if (DEBUG)
		std::cout << "DiamondTrap default constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(std::string _name)
	: ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name) {
	if (DEBUG)
		std::cout << "DiamondTrap parameter constructor called" << std::endl;

	// this->name = _name;
	// this->hitPoints = FragTrap::hitPoints;
	// this->energyPoints = ScavTrap::energyPoints;
	// this->attackDamage = FragTrap::attackDamage;
	FragTrap::setAttackDamage(30);
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoints(50);
	std::cout << "ScavTrap: " << ScavTrap::energyPoints << std::endl;

	std::cout << "DiamondTrap Attack Damage: " << this->attackDamage << std::endl;
	std::cout << "FragTrap Attack Damage: " << FragTrap::attackDamage << std::endl;
	std::cout << "DiamondTrap Energy Points: " << this->energyPoints << std::endl;
	std::cout << "ScavTrap Energy Points: " << ScavTrap::energyPoints << std::endl;
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
