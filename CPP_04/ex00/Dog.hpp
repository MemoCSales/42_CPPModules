#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(std::string type);
	~Dog();
	// Method
	void makeSound() const;
};

#endif