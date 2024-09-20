#include "Cat.hpp"

Cat::Cat() : catBrain(new Brain()){
	if (DEBUG)
		std::cout << WHITE << "🐱 Cat default constructor called" << DEFAULT << std::endl;
	setType("Cat");
}

Cat::Cat(std::string _type) : Animal(_type), catBrain(new Brain()) {
	if (DEBUG)
		std::cout << GREEN << "🐱 Cat parameter constructor called" << DEFAULT << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), catBrain(new Brain (*other.catBrain)) {
	if (DEBUG)
		std::cout << BLUE << "🐱 Cat copy constructor called" << DEFAULT << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		*catBrain = *other.catBrain;
	}
	if (DEBUG)
		std::cout << WHITE << "🐱 Cat operator overload called" << DEFAULT << std::endl;
	return (*this);
}

Cat::~Cat() {
	if (DEBUG)
		std::cout << RED << "🐱 -> 💀 Cat destructor called" << DEFAULT << std::endl;
	delete catBrain;
}

// Method
void Cat::makeSound() const {
	std::cout << "🐱 -> 🔊 Miau, miau!" << std::endl;
}

// Setters
void	Cat::setCatIdea(int index, const std::string& idea) {
	catBrain->setIdea(index, idea);
}

// Getters
std::string Cat::getCatIdea(int index) const {
	return (catBrain->getIdea(index));
}
