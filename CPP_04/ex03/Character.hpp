#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	AMateria* inventory[4];
public:
	Character(std::string name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	~Character();
	// Getters
	std::string const & getName() const;
};


#endif