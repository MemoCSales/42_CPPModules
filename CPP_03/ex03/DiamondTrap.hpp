#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <iostream>
# include <cassert>
# include "../ex00/ClapTrap.hpp"
# include "../ex01/ScavTrap.hpp"
# include "../ex02/FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap (const DiamondTrap& other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();
	void	whoAmI();
};


#endif
