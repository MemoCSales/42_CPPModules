#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <iostream>
# include <cassert>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	// using	FragTrap::hitPoints;
	// using	FragTrap::attackDamage;
	// using	ScavTrap::energyPoints;
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap (const DiamondTrap& other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();
	void	whoAmI();
};


#endif
