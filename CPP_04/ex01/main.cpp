#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Brain brain;
	brain.setIdea(5, "SQUIRREL!");
	// std::cout << "Brain Idea: " << brain.getIdea(5) << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << "Brain Idea (" << i << "): " << brain.getIdea(i) << std::endl;
	}
	
	return 0;
}
