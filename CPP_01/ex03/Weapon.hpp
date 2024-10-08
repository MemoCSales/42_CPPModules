#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

# define DEBUG	0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE	 	"\033[1;37m"
# define DEFAULT	"\033[0m"

class Weapon
{
private:
	std::string	type;
public:
	Weapon(std::string _type);
	Weapon();
	~Weapon();
	//Setters
	void	setType(const std::string& _type);
	//Getter
	const std::string& getType() const;
};


#endif