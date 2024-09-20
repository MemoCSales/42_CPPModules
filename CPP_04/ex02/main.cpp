#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << GREEN << "--- STARTING TESTING ---" << DEFAULT << std::endl;
	// {
	// 	std::cout << "TEST 1: CAN YOU INSTANTIATE AN ANIMAL OBJECT?" << std::endl;
	// 	const Animal* animal = new Animal();
	// 	std::cout << "SOUND: "; 
	// 	animal->makeSound();
	// }

	{
		std::cout << "TEST 2: CAN YOU INSTANTIATE AN ANIMAL OBJECT?" << std::endl;
		const Animal* dog = new Dog("Max");
		const Animal* cat = new Cat("Pepe");
		std::cout << "SOUND: " << std::endl; 
		dog->makeSound();
		cat->makeSound();
		delete cat;
		delete dog;
	}

	// {
	// 	std::cout << "\n---TEST 3: POLYMORPHIC ARRAY OF ANIMALS---" << std::endl;
	// 	Animal* animals[4];

	// 	animals[0] = new Dog();
	// 	animals[1] = new Cat();
	// 	animals[2] = new Dog();
	// 	animals[3] = new Cat();

	// 	for (int i = 0; i < 4; i++) {
	// 		animals[i]->makeSound();
	// 	}
		
	// 	for (int i = 0; i < 4; i++)	{
	// 		delete animals[i];
	// 	}
	// }

	// {
	// 	std::cout << "\n---TEST 4: TRYING TO CREATE A COPY OF THE ABSTRACT ANIMAL---" << std::endl;
	// 	const Animal* animal = new Animal();
	// 	const Animal* anotherAnimal = new Animal(*animal);
		
	// }

	// {
	// 	std::cout << "\n---TEST 5: DERIVED CLASS = BASE CLASS?---" << std::endl;
	// 	Dog dog;
	// 	Animal* animalPtr = &dog;

	// 	animalPtr->makeSound();
	// }
	return 0;
}
