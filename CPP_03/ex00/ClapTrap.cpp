#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void)
{
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
	return ;
}

// Parameter constructor
ClapTrap::ClapTrap(std::string _name) : name(_name), hitPoints(10), energyPoints(10), attackDamage(0) {
	if (DEBUG)
		std::cout << "Parameter constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (DEBUG)
		std::cout << "Assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
	return ;
}

//Setters
void ClapTrap::setName(std::string& _name) {
	if (DEBUG)
		std::cout << "getName member function called " << std::endl;
	name = _name;
}

//Getters
std::string ClapTrap::getName(void) const {
	if (DEBUG)
		std::cout << "getName member function called " << std::endl;
	return name;
}

// Attack public member function
void ClapTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " has no Energy or Hit Points left!" << std::endl;
	}
	
}

// Take Damage member function
void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints > 0) {
		if (amount > hitPoints)
			hitPoints = 0;
		else
			hitPoints -= amount;
		std::cout << "ClapTrap " << name << " took " << amount << " points of damage." << std::endl;
	} else
		std::cout << "ClapTrap " << name << " has " << hitPoints << " and can no longer do anything. " << std::endl;
}

//Repairing member function
void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints > 0 && energyPoints > 0) {
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repair itself " << amount << " points." << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " has " << energyPoints << " and can no longer do anything. " << std::endl;
	}
}