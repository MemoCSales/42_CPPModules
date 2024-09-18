#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

// # define DEBUG 1
class WrongAnimal
{
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	// Methods
	virtual void makeSound() const;
	// Getters
	virtual std::string getType() const;
};


#endif