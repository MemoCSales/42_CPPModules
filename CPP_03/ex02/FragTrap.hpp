#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "../ex00/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();
		void	highFivesGuy(void);
};

#endif