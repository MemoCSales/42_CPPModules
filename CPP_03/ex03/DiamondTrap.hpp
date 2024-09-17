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
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap (const DiamondTrap& other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();
	void	whoAmI();
	// Getters
	std::string	getName() const;
};


#endif
