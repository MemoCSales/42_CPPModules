#include "Brain.hpp"

Brain::Brain(void) {
	if (DEBUG)
		std::cout << "Default Brain constructor called" << std::endl;

	for (int i = 0; i < 100; i++) {
		ideas[i] = "Empty idea";
	}
}

// Copy constructor
Brain::Brain(const Brain& other) {
	if (DEBUG)
		std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
}

// Assignment operator overload
Brain &Brain::operator=(const Brain &other) {
	if (DEBUG)
		std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	if (DEBUG)
		std::cout << "Brain destructor called" << std::endl;
}

// Setters
void	Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index <= 99)
		ideas[index] = idea;
	else
		std::cout << "Error: Invalid index" << std::endl;
}

// Getters
std::string Brain::getIdea(int index) const {
	if (index >= 0 && index <= 99)
		return (ideas[index]);
	else
		return ("Invalid index!");
}
