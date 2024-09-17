#include "DiamondTrap.hpp"

int main() {
	std::cout << GREEN << "\n--- TESTS DIAMONDTRAP ---" << DEFAULT << std::endl;
	{
		std::cout << "\n--- TEST 1: Attributes Inheritance ---" << std::endl;
		DiamondTrap diamond("DiamondTrap");
		ScavTrap defaultScav("ScavTrap");
		FragTrap defaultFrag("FragTrap");

		assert(diamond.getHitPoints() == defaultFrag.getHitPoints());
		assert(diamond.getEnergyPoints() == defaultScav.getEnergyPoints());
		assert(diamond.getAttackDamage() == defaultFrag.getAttackDamage());
		std::cout << "DiamondTrap Name: " << WHITE << diamond.getName() << DEFAULT << std::endl;
		std::cout << "ClapTrap Name: " << YELLOW << diamond.ClapTrap::getName() << DEFAULT << std::endl;
		std::cout << "Energy Points for DiamondTrap: " << GREEN << diamond.getEnergyPoints() << DEFAULT << std::endl;
		std::cout << "Energy Points for ScavTrap: " << GREEN << defaultScav.getEnergyPoints() << DEFAULT << std::endl;
		std::cout << "Hit Points for DiamondTrap: " << BLUE << diamond.getHitPoints() << DEFAULT << std::endl;
		std::cout << "Hit Points for FragTrap: " << BLUE << defaultFrag.getHitPoints() << DEFAULT << std::endl;
		std::cout << "Attack Damage for DiamondTrap: " << RED << diamond.getAttackDamage() << DEFAULT << std::endl;
		std::cout << "AttackDamage FragTap: " << RED << defaultFrag.getAttackDamage() << DEFAULT << std::endl;
		std::cout << "----------" << std::endl;
	}
	{
		std::cout << "\n--- TEST 2: Attack Functionality from ScavTrap ---" << std::endl;
		DiamondTrap diamond("Diamond");

		diamond.attack("TargetBot");
		std::cout << "🔋 Energy Points after attack: " << diamond.getEnergyPoints() << std::endl;
	}
	{
		std::cout << "\n--- TEST 3: DiamondTrap Special Functionality ---" << std::endl;
		DiamondTrap diamond("DiamondBot");

		diamond.whoAmI();
	}
	{
		std::cout << "\n--- TEST 4: Combat Simulation ---" << std::endl;
		DiamondTrap diamond("DiamondBot");

		diamond.attack("TargetBot");
		diamond.takeDamage(30);
		diamond.beRepaired(20);

		std::cout << "👊 Final Hit Points: " << diamond.getHitPoints() << std::endl;
		std::cout << "🔋 Final Energy Points: " << diamond.getEnergyPoints() << std::endl;
	}
	return (0);
}
