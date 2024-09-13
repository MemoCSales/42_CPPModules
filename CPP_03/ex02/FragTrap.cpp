#include "../ex00/ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	if (DEBUG)
		std::cout << "FrapTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	if (DEBUG)
		std::cout << "FragTrap parameter constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (DEBUG)
		std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}


FragTrap::~FragTrap() {
	if (DEBUG)
		std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuy(void) {
	std::cout << "FragTrap " << YELLOW << getName() << DEFAULT << " is asking for high fives ✋" << std::endl;
}
