#include "AMateria.hpp"
#include "IMateriaSource.hpp"

int main() {
	std::cout << GREEN << "--- STARTING TESTING ---" << DEFAULT << std::endl;
	{
		std::cout << "TEST 1: SUBJECT MAIN" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;

	}
	return 0;
}