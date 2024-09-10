#include "../ex00/ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	{
		std::cout << GREEN << "\n--- TEST 1: Initial Test ---" << DEFAULT << std::endl;
		ScavTrap bot("ScavTrap_2025");
		std::cout << WHITE << "ScavTrap attributes: " << bot.getName() << DEFAULT << std::endl;
		std::cout << "Energy Points for ScavTrap: " << GREEN << bot.getEnergyPoints() << DEFAULT << std::endl;
		std::cout << "Hit Points for ScavTrap: " << BLUE << bot.getHitPoints() << DEFAULT << std::endl;
		std::cout << "Attack Damage for ScavTrap: " << RED << bot.getAttackDamage() << DEFAULT << std::endl;
		bot.guardGate();
	}
	{
		std::cout << GREEN << "\n--- TEST 2: ScavTrap Inheritance Test ---" << DEFAULT << std::endl;
		ScavTrap bot1("ScavTrap Alpha");
		ScavTrap bot2("ScavTrap Beta");
		
		bot1.attack("ScavTrap Beta");
		bot2.takeDamage(20);
	}
	{
		std::cout << GREEN << "\n--- TEST 3: ScavTrap Repairing Test ---" << DEFAULT << std::endl;
		ScavTrap bot("ScavTrap Guardian");
		bot.beRepaired(10);
		std::cout << "Energy left: " << bot.getEnergyPoints() << std::endl;
		std::cout << "Hit points: " << bot.getHitPoints() << std::endl;
	}
	{
		//bot should still be able to call guardGate regardless of energy
		std::cout << GREEN << "\n--- TEST 4: ScavTrap Energy Depletion Test ---" << DEFAULT << std::endl;
		ScavTrap bot("Exhausted ScavTrap");

		for (int i = 0; i < 51; i++) {
			bot.attack("Target");
		}
		bot.beRepaired(5);
		bot.guardGate();
	}
	{
		std::cout << GREEN << "\n--- TEST 5: ScavTrap Destruction Chain test ---" << DEFAULT << std::endl;
		ScavTrap bot("Temporary ScavTrap");
	}
	return (0);
}