#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout << GREEN << "\n---TEST 1: SUBJECT TEST---" << DEFAULT << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << GREEN << "\n---TEST 2: OBJECT CREATION---" << DEFAULT << std::endl;
		Animal	meta;
		Dog		dog;
		Cat		cat;
		std::cout << BLUE << "TYPES:" << DEFAULT << std::endl;
		std::cout << meta.getType() << std::endl;
		std::cout << dog.getType() << std::endl;
		std::cout << cat.getType() << std::endl;

		std::cout << BLUE << "SOUNDS: " << DEFAULT << std::endl;
		meta.makeSound();
		dog.makeSound();
		cat.makeSound();
		std::cout << BLUE << "\nDESTRCUTORS: " << DEFAULT << std::endl;

	}
	{
		std::cout << GREEN << "\n---TEST 3: ARRAY OF POINTERS---" << DEFAULT << std::endl;
		const Animal* animals[3];

		animals[0] = new Animal();
		animals[1] = new Dog();
		animals[2] = new Cat();

		for(int i = 0; i < 3; i++) {
			std::cout << BLUE << "TYPE -> " << DEFAULT << animals[i]->getType() << std::endl;
			std::cout << WHITE << "SOUND: " << DEFAULT;
			animals[i]->makeSound();
		}

		for (int i = 0; i < 3; i++)	{
			delete animals[i];
		}
		
	}
	{
		std::cout << GREEN << "\n---TEST 4: COPYING AND ASSIGNMENT---" << DEFAULT << std::endl;
		Dog	originalDog;
		Dog copyDog = originalDog;

		std::cout << BLUE << "TYPE -> " << DEFAULT << copyDog.getType() << std::endl;
		std::cout << WHITE << "SOUND: " << DEFAULT;
		copyDog.makeSound();

		Cat originalCat;
		Cat copyCat;
		copyCat = originalCat;

		std::cout << BLUE << "TYPE -> " << DEFAULT << copyCat.getType() << std::endl;
		std::cout << WHITE << "SOUND: " << DEFAULT;
		copyCat.makeSound();
	}
	{
		const Animal* 	animal = NULL;

		if (animal == NULL) {
			std::cout << RED << "NULL pointer, cannot make sound!" << DEFAULT << std::endl;
		}

		class Bird : public Animal {};

		const Animal* bird = new Bird();
		bird->makeSound();	// Should call the base class's makeSound since Bird does not override

		delete bird;
	}
	return 0;
}