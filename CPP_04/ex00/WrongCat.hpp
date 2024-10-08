#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();
	// Methods
	virtual void makeSound() const;
	// Getters
	virtual std::string getType() const;
};


#endif