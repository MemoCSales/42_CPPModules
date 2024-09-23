#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main() {
	// std::cout << GREEN << "--- STARTING TESTING ---" << DEFAULT << std::endl;
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
	{
		std::cout << "TEST 2: TESTING CLONE METHOD" << std::endl;
		AMateria* materia = new Cure();
		Character hero("HeroName");
		materia->use(hero);

		AMateria* cloneMateria = materia->clone();
		cloneMateria->use(hero);

		std::cout << "Memory address of the original Materia: " << &materia << std::endl;
		std::cout << "Memory address of the cloned Materia: " << &cloneMateria << std::endl;

		delete materia;
		delete cloneMateria;

	}
	return 0;
}