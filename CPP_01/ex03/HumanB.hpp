#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon* type;
public:
	HumanB(std::string _name);
	~HumanB();
	void	attack();
	//Setters
	void    setWeapon(Weapon& _type);
};

#endif