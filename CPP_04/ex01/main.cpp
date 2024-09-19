#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	{
		// Checks that the correct derived class destructor will be called
		std::cout << "\n---TEST 1: TESTING POLYMORPHISM---" << std::endl;
		Animal* array[10];
		for (int i = 0; i < 10; i++)
		{
			if (i <= 4) {
				array[i] = new Dog();
			} else {
				array[i] = new Cat();
			}
		}
		for (int i = 0; i < 10; i++)
		{
			std::cout << i << ": ";
			array[i]->makeSound();
			delete array[i];
		}	
	}

	{
		std::cout << "\n---TEST 2: SUBJECT TEST---" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;
		delete i;

	}

	{
		// Modify the Brain in one Dog object and verify that the changes do not affect the other Dog
		std::cout << "\n---TEST 3: TEST DEEP COPY---" << std::endl;
		Dog dog("Max");
		Dog copyDog("Copy of Max");
		dog = copyDog;
		Cat cat("Paws");
		Cat copyCat("Copy of Paws");
		cat = copyCat;

		dog.setDogIdea(0, "SQUIRREL!");
		std::cout << "Max's Idea: " << dog.getDogIdea(0) << std::endl;
		std::cout << "Copy of Max's Idea: " << copyDog.getDogIdea(0) << std::endl;
		dog.setDogIdea(0, "Chase the mail man!");
		std::cout << "Max's Idea: " << dog.getDogIdea(0) << std::endl;
		std::cout << "Copy of Max's Idea: " << copyDog.getDogIdea(0) << std::endl;

		cat.setCatIdea(0, "Miau");
		std::cout << "Paws's Idea: " << cat.getCatIdea(0) << std::endl;
		std::cout << "Copy of Paws's Idea: " << copyCat.getCatIdea(0) << std::endl;
	}

	{
		// Edge Cases with Brain Manipulation
		std::cout << "\n---TEST 4: TEST BRAIN MANIPULATION---" << std::endl;
		Brain brain;
		
		brain.setIdea(-1, "Invalid idea");
		brain.setIdea(100, "Invalid idea");

		std::cout << brain.getIdea(-1) << std::endl;
		std::cout << brain.getIdea(100) << std::endl;

		brain.setIdea(0, "First idea");
		brain.setIdea(99, "Last idea");

		std::cout << brain.getIdea(0) << std::endl;
		std::cout << brain.getIdea(99) << std::endl;
	}

	{
		// Edge Cases with Brain Manipulation
		std::cout << "\n---TEST 5: MEMORY MANAGEMENT TEST---" << std::endl;
		Animal* animals[4];

		animals[0] = new Dog();
		animals[1] = new Cat();
		animals[2] = new Dog();
		animals[3] = new Cat();

		for (int i = 0; i < 4; i++)	{
			delete animals[i];
		}
	}
	
	{
		// Ensure that assigning an object to itself doesn't cause double deletion or memory corruption
		std::cout << "\n---TEST 6: EDGE CASE COPYINH AND ASSIGNMENT---" << std::endl;

		Dog dog;
		
		dog.setDogIdea(0, "Chase cats");

		dog = dog;

		std::cout << dog.getDogIdea(0) << std::endl;
	}
	return 0;
}
