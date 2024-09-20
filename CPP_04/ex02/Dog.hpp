#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* dogBrain;
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();
		// Method
		void makeSound() const;
		// Setters
		void	setDogIdea(int index, const std::string &idea);
		// Getters
		std::string getDogIdea(int index) const;
};

#endif
