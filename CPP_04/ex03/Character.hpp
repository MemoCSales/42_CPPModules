#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"


extern AMateria* unequippedMateria[4];
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
	AMateria* getMateria(int idx) const;
	// Method
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};


#endif
