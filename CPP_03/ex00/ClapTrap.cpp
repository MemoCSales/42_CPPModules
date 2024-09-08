#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void)
{
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
	return ;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	if (DEBUG)
		std::cout << "Copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (DEBUG)
		std::cout << "Assignment operator called" << std::endl;
	// (void) other;
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
	return ;
}

//Setters
void ClapTrap::setName(std::string& _name) {
	if (DEBUG)
		std::cout << "getName member function called " << std::endl;
	name = _name;
}

//Getters
std::string ClapTrap::getName(void) const {
	if (DEBUG)
		std::cout << "getName member function called " << std::endl;
	return name;
}

// Attack public member function
void ClapTrap::attack(const std::string& target) {
	// std::cout << "ClapTrap " << st
}