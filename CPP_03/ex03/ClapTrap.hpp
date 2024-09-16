#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

# define DEBUG 1
# define MAX_HIT_POINTS 10

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE	 	"\033[1;37m"
# define DEFAULT	"\033[0m"

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hitPoints;
		int				energyPoints;
		int				attackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		//Setters
		void			setHitPoints(unsigned int hp);
		void			setEnergyPoints(int energy);
		void			setAttackDamage(int damage);
		//Getters
		std::string		getName() const;
		unsigned int	getHitPoints() const;
		int				getEnergyPoints() const;
		int				getAttackDamage() const;
		//Member function
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif

