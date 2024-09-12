#include "../ex00/ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::cout << GREEN << "\n--- TESTS FRAGTRAP ---" << DEFAULT << std::endl;
	{
		std::cout << GREEN << "\n--- TEST 1: Initial Test ---" << DEFAULT << std::endl;
		FragTrap bot("FragTrap_2025");
		std::cout << WHITE << "ScavTrap attributes: " << bot.getName() << DEFAULT << std::endl;
		std::cout << "Energy Points for ScavTrap: " << GREEN << bot.getEnergyPoints() << DEFAULT << std::endl;
		std::cout << "Hit Points for ScavTrap: " << BLUE << bot.getHitPoints() << DEFAULT << std::endl;
		std::cout << "Attack Damage for ScavTrap: " << RED << bot.getAttackDamage() << DEFAULT << std::endl;
		bot.highFivesGuy();
	}
	{
		std::cout << GREEN << "\n--- TEST 2: FragTrap Attack and Damage Handling ---" << DEFAULT << std::endl;
		FragTrap attacker("FragTrap_Attacker");
		FragTrap target("FragTrap_Target");

		attacker.attack("FrapTrap_Target");
		target.takeDamage(30);

		attacker.beRepaired(20);
		std::cout << "Attacker Hit Points after repair: " << attacker.getHitPoints() << std::endl;
	}
	{
		std::cout << GREEN << "\n--- TEST 3: FragTrap Energy Management ---" << DEFAULT << std::endl;
		FragTrap bot("FragTrap_EnergyTest");

		for (int i = 0; i < 101; i++) {
			bot.attack("Dummy_Target");
		}

		// Try to repair but it should fail because of no energy
		bot.beRepaired(10);

		bot.highFivesGuy();
	}
	{
		std::cout << GREEN << "\n--- TEST 4: FragTrap Destruction Chain ---" << DEFAULT << std::endl;
		FragTrap bot("FragTrap_Destructor");
	}
	{
		std::cout << GREEN << "\n--- TEST 5: FragTrap Special Abilities ---" << DEFAULT << std::endl;
		FragTrap bot("FragTrap_Special");

		std::cout << "Initial Energy Points: " << GREEN << bot.getEnergyPoints() << DEFAULT << std::endl;
		std::cout << "Initial Hit Points: " << BLUE << bot.getHitPoints() << DEFAULT << std::endl;

		bot.attack("Target");
		bot.highFivesGuy();
		std::cout << "Energy Points of " << bot.getName() << " after attack: " << GREEN << bot.getEnergyPoints() << DEFAULT << std::endl;

		bot.highFivesGuy();
		bot.highFivesGuy();
	}
	return 0;
}