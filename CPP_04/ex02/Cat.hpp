#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* catBrain;
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();
		// Method
		void makeSound() const;
		// Setters
		void	setCatIdea(int index, const std::string &idea);
		// Getters
		std::string getCatIdea(int index) const;
};

#endif