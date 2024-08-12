#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

# define DEBUG	1

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE	 	"\033[1;37m"
# define DEFAULT	"\033[0m"

class Zombie
{
private:
	std::string name;
public:
	Zombie(std::string _name);
	Zombie();
	~Zombie();
	void announce(void);
	void randomChump(std::string name);
	Zombie* newZombie(std::string name);
	Zombie* zombieHorde(int N, std::string name);

	//Setters
	void	setZombieName(const std::string &zombieName);
	//Getters
	std::string getZombieName() const;
};

#endif