#include "Dog.hpp"

Dog::Dog() : dogBrain(new Brain()) {
	if (DEBUG)
		std::cout << WHITE << "🐶 Dog default constructor called" << DEFAULT << std::endl;
	setType("Dog");
}

Dog::Dog(std::string _type) : Animal(_type), dogBrain(new Brain()) {
	if (DEBUG)
		std::cout << GREEN << "🐶 Dog parameter constructor called" << DEFAULT << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), dogBrain(new Brain(*other.dogBrain)) {
	if (DEBUG)
		std::cout << BLUE << "🐶 Dog copy constructor called" << DEFAULT << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		*dogBrain = *other.dogBrain;
	}
	if (DEBUG)
		std::cout << WHITE << "🐶 Dog operator overload called" << DEFAULT << std::endl;
	return (*this);
}

Dog::~Dog() {
	if (DEBUG)
		std::cout << RED << "🐶 -> 💀 Dog destructor called" << DEFAULT << std::endl;
	delete dogBrain;
}

// Method
void Dog::makeSound() const {
	std::cout << "🐶 -> 🔊 Guau, guau!" << std::endl;
}

// Setters
void	Dog::setDogIdea(int index, const std::string& idea) {
	dogBrain->setIdea(index, idea);
}

// Getters
std::string Dog::getDogIdea(int index) const {
	return (dogBrain->getIdea(index));
}
