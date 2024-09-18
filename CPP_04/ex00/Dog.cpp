#include "Dog.hpp"

Dog::Dog() {
	if (DEBUG)
		std::cout << "Dog default constructor called" << std::endl;
	setType("Dog");
}

Dog::Dog(std::string _type) : Animal(_type) {
	if (DEBUG)
		std::cout << "🐶 Dog parameter constructor called" << std::endl;
}

Dog::~Dog() {
	if (DEBUG)
		std::cout << "🐶 -> 💀 Dog destructor called" << std::endl;
}

// Method
void Dog::makeSound() const {
	std::cout << "🐶 -> 🔊 Guau, guau!" << std::endl;
}
