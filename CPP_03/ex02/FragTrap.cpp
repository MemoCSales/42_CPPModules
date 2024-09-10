#include "../ex00/ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	if (DEBUG)
		std::cout << "FragTrap parameter constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::~FragTrap() {
	if (DEBUG)
		std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuy(void) {
	std::cout << "FragTrap " << YELLOW << getName() << DEFAULT << " is asking for high fives ✋" << std::endl;
}