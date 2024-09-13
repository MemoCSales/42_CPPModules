#include "DiamondTrap.hpp"

int main() {
	std::cout << GREEN << "\n--- TESTS FRAGTRAP ---" << DEFAULT << std::endl;
	{
		std::cout << "\n--- TEST 1: DiamondTrap Constructor ---" << std::endl;
		DiamondTrap diamond("DiamondTrap");
		ScavTrap defaultScav("ScavTrap");
		FragTrap defaultFrag("FragTrap");

		// assert(diamond.getHitPoints() == defaultFrag.getHitPoints());
		// assert(diamond.getEnergyPoints() == defaultScav.getEnergyPoints());
		// assert(diamond.getAttackDamage() == defaultFrag.getAttackDamage());
		// std::cout << "Energy Points for DiamondTrap: " << GREEN << diamond.getEnergyPoints() << DEFAULT << std::endl;
		// std::cout << "Hit Points for DiamondTrap: " << BLUE << diamond.getHitPoints() << DEFAULT << std::endl;
		std::cout << "Attack Damage for DiamondTrap: " << RED << diamond.getAttackDamage() << DEFAULT << std::endl;
		std::cout << "AttackDamage FragTap: " << GREEN << defaultFrag.getAttackDamage() << DEFAULT << std::endl;
		std::cout << "----------" << std::endl;
	}
	return (0);
}