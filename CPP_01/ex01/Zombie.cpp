#include "Zombie.hpp"

//Setters
void	Zombie::setZombieName(const std::string &zombieName) {
	name = zombieName;
}

//Getters
std::string Zombie::getZombieName() const {
	return name;
}

void    Zombie::announce(void) {
	
	std::cout << getZombieName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string _name)
{
	name = _name;
	if (DEBUG)
		std::cout << "Paramatered constuctor called" << std::endl;

}

Zombie::~Zombie()
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
}
Zombie::Zombie() 
{
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
}