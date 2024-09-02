#include "Fixed.hpp"

// Setter
void    Fixed::setRawBits(int const _raw) {
    //Something about fixed-point numbers goes here
	raw = _raw;
	std::cout << "setRawBits member function called" << std::endl;
}

//Getters
int     Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return raw;
}

//Constructor
Fixed::Fixed () {
	std::cout << "Default constructor called" << std::endl;
	raw = 0;
}

//Copy constructor
/* A constructor which creates and object by initializing it with an object of the same
class, which has been created previously. */
Fixed::Fixed(const Fixed& b) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = b;
}

//Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

//Move Assignment Operator Overload
Fixed &Fixed::operator=(const Fixed& F) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &F) {
		raw = F.getRawBits();
	}
	return *this;
}