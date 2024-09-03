#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		int	hitPoints = 10;
		int	enPoints = 10;
		int	attPoints = 10;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		//Member function
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif

