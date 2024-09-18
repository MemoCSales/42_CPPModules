#include "WrongCat.hpp"
#include "Animal.hpp"


WrongCat::WrongCat() {
	if (DEBUG)
		std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	if (DEBUG)
		std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "🔊 Cat sound but wrong 🔊" << std::endl;
}

std::string WrongCat::getType() const {
	return "Wrong Cat";
}