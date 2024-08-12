#include "Zombie.hpp"

void	Zombie::randomChump(std::string _name) {
	Zombie	zombie(_name);
	std::cout << GREEN << "Part 3: " << DEFAULT << std::endl;
	zombie.announce();
}