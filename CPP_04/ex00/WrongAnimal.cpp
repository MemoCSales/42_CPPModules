#include "WrongAnimal.hpp"
#include "Animal.hpp"

WrongAnimal::WrongAnimal() {
	if (DEBUG)
		std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	if (DEBUG)
		std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "🔊 WrongAnimal sound 🔊" << std::endl;
}

std::string WrongAnimal::getType() const {
	return "Wrong Animal";
}
