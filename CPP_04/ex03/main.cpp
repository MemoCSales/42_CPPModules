#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
	std::cout << GREEN << "--- STARTING TESTING ---" << DEFAULT << std::endl;
	// {
	// 	std::cout << "TEST 1: SUBJECT MAIN" << std::endl;
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());

	// 	ICharacter* me = new Character("me");

	// 	AMateria* tmp;
	// 	tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);

	// 	ICharacter* bob = new Character("bob");

	// 	me->use(0, *bob);
	// 	me->use(1, *bob);

	// 	delete bob;
	// 	delete me;
	// 	delete src;

	// }
	// return (0);
	// {
	// 	std::cout << "TEST 2: TESTING CLONE METHOD" << std::endl;
	// 	AMateria* materia = new Cure();
	// 	Character hero("HeroName");
	// 	materia->use(hero);

	// 	AMateria* cloneMateria = materia->clone();
	// 	cloneMateria->use(hero);

	// 	std::cout << "Memory address of the original Materia: " << &materia << std::endl;
	// 	std::cout << "Memory address of the cloned Materia: " << &cloneMateria << std::endl;

	// 	delete materia;
	// 	delete cloneMateria;
	// }
	// 	{
	// 	std::cout << "TEST 3: TESTING COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR FOR CHARACTER" << std::endl;
	// 	AMateria* cure = new Cure();
	// 	AMateria* ice = new Ice();
	// 	Character hero("Hero");

	// 	// Equip materia to hero
	// 	hero.equip(cure);
	// 	hero.equip(ice);

	// 	// Test copy constructor
	// 	Character heroCopy(hero);
	// 	std::cout << "Original Hero: " << hero.getName() << std::endl;
	// 	std::cout << "Copied Hero: " << heroCopy.getName() << std::endl;

	// 	// Use materia from copied hero
	// 	heroCopy.use(0, hero);
	// 	heroCopy.use(1, hero);

	// 	// Test assignment operator
	// 	Character anotherHero("AnotherHero");
	// 	anotherHero = hero;
	// 	std::cout << "Original Hero: " << hero.getName() << std::endl;
	// 	std::cout << "Assigned Hero: " << anotherHero.getName() << std::endl;

	// 	// Use materia from assigned hero
	// 	anotherHero.use(0, hero);
	// 	anotherHero.use(1, hero);

	// 	delete cure;
	// 	delete ice;
	// }
	// return (0);

	// {
	// 	std::cout << "TEST 4: TESTING LEARN MATERIA WITH NULL" << std::endl;
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(NULL);

	// 	AMateria* tmp = src->createMateria("ice");
	// 	if (tmp == NULL) {
	// 		std::cout << GREEN << "Successfully handled learning NULL pointer!" << DEFAULT << std::endl;
	// 	}
	// 	delete src;
	// }
	// return (0);
	// {
	// 	std::cout << "TEST 5: TESTING CAPACITY LIMITS" << std::endl;
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	src->learnMateria(new Ice()); // This one should not be stored

	// 	std::cout << YELLOW << "LEARNED MATERIA:" << DEFAULT << std::endl;
	// 	for (int i = 0; i < 4; i++) {
	// 		std::cout << "+-------+" << std::endl;  // Top border of the box
	// 		std::cout << "| ";
			
	// 		// Check which Materia is equipped and print the corresponding emoji
	// 		AMateria* materia = static_cast<MateriaSource*>(src)->getMateriaSource(i);
	// 		if (materia != NULL) {
	// 			if (materia->getType() == "ice") {
	// 				std::cout << "❄️ ";  // Ice emoji
	// 			} else if (materia->getType() == "cure") {
	// 				std::cout << "💊 ";  // Cure emoji
	// 			}
	// 		} else {
	// 			std::cout << "   ";  // Empty space for unequipped
	// 		}
	// 		std::cout << "|" << std::endl;  // Right border of the box
   	// 	 }
	// 		std::cout << "+-------+" << std::endl;  // Bottom border of the box
		

	// 	Character hero("Hero");
	// 	AMateria* tmp1 = src->createMateria("ice");
	// 	AMateria* tmp2 = src->createMateria("cure");
	// 	hero.equip(tmp1);
	// 	hero.equip(tmp2);

	// 	std::cout << YELLOW << "INVENTORY:" << DEFAULT << std::endl;

	// 	for (int i = 0; i < 4; i++) {
	// 		std::cout << "+-------+" << std::endl;  // Top border of the box
	// 		std::cout << "| ";
			
	// 		// Check which Materia is equipped and print the corresponding emoji
	// 		if (hero.getMateria(i) != NULL) {
	// 			if (hero.getMateria(i)->getType() == "ice") {
	// 				std::cout << "❄️ ";  // Ice emoji
	// 			} else if (hero.getMateria(i)->getType() == "cure") {
	// 				std::cout << "💊 ";  // Cure emoji
	// 			}
	// 		} else {
	// 			std::cout << "   ";  // Empty space for unequipped
	// 		}

	// 		std::cout << "|" << std::endl;  // Right border of the box
   	// 	 }
	// 		std::cout << "+-------+" << std::endl;  // Bottom border of the box

	// 	if (tmp1)
	// 	{
	// 		std::cout << GREEN << "Successfully learned 4 Materia, limit intact" << DEFAULT << std::endl;
	// 	} else {
	// 		std::cout << "No more Materia can be learned" << std::endl;
	// 	}
		
	// 	delete tmp1;
	// 	delete tmp2;
	// 	delete src;
	// }
	// return (0);
	// {
	// 	std::cout << "TEST 6: TESTING createMateria WITH UNKNOWN TYPE" << std::endl;
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());

	// 	AMateria* tmp = src->createMateria("unknown");
	// 	if (tmp == NULL)
	// 	{
	// 		std::cout << GREEN << "Successfully returned a NULL pointer for unknown type!" << DEFAULT << std::endl;
	// 	} else {
	// 		std::cout << "Error: created a Materia for unknown type" << std::endl;
	// 	}
	// 	delete src;
	// }
	// return (0);
	// {
	// 	std::cout << "TEST 7: TESTING CHARACTER WITHOUT EQUIPPED MATERIA" << std::endl;
	// 	ICharacter* character = new Character("NoMateria");
	// 	ICharacter* target = new Character("Target");

	// 	// Trying to use Materia when there is nothing equipped
	// 	character->use(0, *target);
	// 	std::cout << GREEN << "Handled use with no equipped Materia" << DEFAULT << std::endl;

	// 	delete character;
	// 	delete target;
	// }
	// return (0);
	// {
	// 	std::cout << "TEST 8: TESTING COPY CONSTRUCTOR FOR MATERIASOURCE" << std::endl;
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());

	// 	// Copy the MateriaSource
	// 	IMateriaSource* srcCopy = new MateriaSource(*static_cast<MateriaSource*>(src));

	// 	// Creating a new character and using the original source
	// 	ICharacter* char1 = new Character("Character 1");
	// 	AMateria* tmp1 = src->createMateria("ice");
	// 	char1->equip(tmp1);
	// 	char1->use(0, *char1);

	// 	// Create a new Character and use the copied source
	// 	ICharacter* char2 = new Character("Character 2");
	// 	AMateria* tmp2 = srcCopy->createMateria("cure");
	// 	char2->equip(tmp2);
	// 	char2->use(0, *char2);

	// 	std::cout << GREEN << "Original and copy used independently" << DEFAULT << std::endl;

	// 	delete srcCopy;
	// 	delete src;
	// 	delete char1;
	// 	delete char2;
	// 	delete tmp1;
	// 	delete tmp2;
	// }
	// return 0;
	{
		std::cout << "TEST 9: TESTING UNEQUIP & EQUIP METHOD FUNCTION" << std::endl;

		Character hero("Hero");

		AMateria* ice = new Ice();
		AMateria* cure = new Cure();

		hero.equip(ice);
		hero.equip(cure);

		std::cout << "Before unequip: " << std::endl;
		for (int i = 0; i < 4; i++) {
			std::cout << "+-------+" << std::endl;
			std::cout << "| ";
			
			if (hero.getMateria(i) != NULL) {
				if (hero.getMateria(i)->getType() == "ice") {
					std::cout << "❄️ ";
				} else if (hero.getMateria(i)->getType() == "cure") {
					std::cout << "💊 ";
				}
			} else {
				std::cout << "   ";
			}

			std::cout << "|" << std::endl;
   		 }
		std::cout << "+-------+" << std::endl;
		
		hero.unequip(0);

		std::cout << "\nAfter unequip: " << std::endl;
		for (int i = 0; i < 4; i++) {
			std::cout << "+-------+" << std::endl;
			std::cout << "| ";
			
			if (hero.getMateria(i) != NULL) {
				if (hero.getMateria(i)->getType() == "ice") {
					std::cout << "❄️ ";
				} else if (hero.getMateria(i)->getType() == "cure") {
					std::cout << "💊 ";
				}
			} else {
				std::cout << "   ";
			}

			std::cout << "|" << std::endl;
   		 }
		std::cout << "+-------+" << std::endl;

		hero.equip(ice);
		std::cout << "\nAfter equip AGAIN: " << std::endl;
		for (int i = 0; i < 4; i++) {
			std::cout << "+-------+" << std::endl;
			std::cout << "| ";
			
			if (hero.getMateria(i) != NULL) {
				if (hero.getMateria(i)->getType() == "ice") {
					std::cout << "❄️ ";
				} else if (hero.getMateria(i)->getType() == "cure") {
					std::cout << "💊 ";
				}
			} else {
				std::cout << "   ";
			}

			std::cout << "|" << std::endl;
   		 }
		std::cout << "+-------+" << std::endl;

		delete ice;
		delete cure;
	}
	return 0;
}
