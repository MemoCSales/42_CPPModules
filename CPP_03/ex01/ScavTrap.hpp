#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "../ex00/ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap& other);
		ScavTrap &operator=(const ScavTrap &other);
		ScavTrap(std::string name);
		~ScavTrap();
		void	guardGate();
};

#endif