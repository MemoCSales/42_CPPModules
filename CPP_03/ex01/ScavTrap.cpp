#include "../ex00/ClapTrap.hpp"
#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name) {
	if (DEBUG)
		std::cout << "ScavTrap parameter constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::~ScavTrap() {
    if (DEBUG)
        std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " <<  YELLOW << getName() << DEFAULT << " is now in Gatekeeper Mode!" << std::endl;
}
