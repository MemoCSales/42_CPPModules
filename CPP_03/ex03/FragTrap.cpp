#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	if (DEBUG)
		std::cout << "FrapTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name) {
	if (DEBUG)
		std::cout << "FragTrap parameter constructor called" << std::endl;

	setHitPoints(FragTrap::_hitPoints = 100);
	setAttackDamage(FragTrap::_attackDamage = 30);
	this->energyPoints = 100;
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
