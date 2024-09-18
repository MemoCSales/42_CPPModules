#include "Cat.hpp"

Cat::Cat() {
	if (DEBUG)
		std::cout << "Cat default constructor called" << std::endl;
	setType("Cat");
}

Cat::Cat(std::string _type) : Animal(_type) {
	if (DEBUG)
		std::cout << "🐱 Cat parameter constructor called" << std::endl;
}

Cat::~Cat() {
	if (DEBUG)
		std::cout << "🐱 -> 💀 Cat destructor called" << std::endl;
}

// Method
void Cat::makeSound() const {
	std::cout << "🐱 -> 🔊 Miau, miau!" << std::endl;
}
