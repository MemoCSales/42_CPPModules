#include "ClapTrap.hpp"

int main() {
	{
		std::cout << GREEN << "Test 1" << DEFAULT << std::endl;
		ClapTrap bot("Clapbot 3000");
		ClapTrap bot2("Clapzilla");

		bot.attack("Clapzilla");
		bot2.takeDamage(1);
		std::cout << std::endl;
	}
	{
		std::cout << GREEN << "Test 2" << DEFAULT << std::endl;
		ClapTrap bot("Clapbot 3000");

		bot.takeDamage(5);
		bot.beRepaired(3);
		std::cout << std::endl;
	}
	{
		std::cout << GREEN << "Test 3: Zero Energy or Zero Hit Points" << DEFAULT << std::endl;
		ClapTrap bot("Clapbotbot");

		bot.takeDamage(10);
		bot.attack("Clapzilla");
		std::cout << std::endl;
	}
	{
		std::cout << GREEN << "Test 4: Excessive Damage" << DEFAULT << std::endl;
		ClapTrap bot("Clapbot 2025");

		bot.takeDamage(20);
		std::cout << std::endl;
	}
	{
		std::cout << GREEN << "Test 5: Repeated Attacks Until Out of Energy" << DEFAULT << std::endl;
		ClapTrap ironman("Iron Man");
		ClapTrap thor("Thor");

		for (int i = 0; i < 11; i++) {
			ironman.attack("Thor");
			thor.takeDamage(1);
		}
		std::cout << std::endl;
	}
	{
		std::cout << GREEN << "Test 6: Full Repair Until Energy Runs Out" << DEFAULT << std::endl;
		ClapTrap bot("Iron Man");

		bot.takeDamage(7);

		for (int i = 0; i < 4; i++) {
			bot.beRepaired(2);
		}
		std::cout << std::endl;
	}
	std::cout << RED << "----------TEST FINISHED---------------" << DEFAULT << std::endl;
	return 0;
}