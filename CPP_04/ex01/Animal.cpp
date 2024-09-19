#include "Animal.hpp"

Animal::Animal(void) {
	if (DEBUG)
		std::cout << "🐾 Animal default constructor called" << std::endl;
	setType("Generic Animal");
}

Animal::Animal(std::string _type) : type(_type) 
{
	if (DEBUG)
		std::cout << "🐾 Animal parameter constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	if (DEBUG)
		std::cout << "Animal copy constructor called" << std::endl;
	// if (this != &other) {
		this->type = other.type;
	// }
}

Animal &Animal::operator=(const Animal &other) {
	if (DEBUG)
		std::cout << "Animal Operator Overload called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

// Virtual function makeSound
void Animal::makeSound() const {
	std::cout << MAGENT << "🫠  -> 🔊 I do a generic sound" << DEFAULT << std::endl;
}

Animal::~Animal()
{
	if (DEBUG)
		std::cout << RED << "🐾 Animal destructor called" << DEFAULT << std::endl;
}

//Setters
void	Animal::setType(std::string _type) {
	type = _type;
}
// Getters
std::string Animal::getType() const {
	return type;
}
