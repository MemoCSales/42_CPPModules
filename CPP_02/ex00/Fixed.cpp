#include "Fixed.hpp"

// Setter
void    Fixed::setRawBits(int const _raw) {
    //Something about fixed-point numbers goes here
	raw = _raw;
	std::cout << "set function called" << std::endl;
}

//Getters
int     Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return raw;	//fixed this
}

//Constructor
Fixed::Fixed () {
	std::cout << "Default constructor called" << std::endl;
}

//Copy constructor
/*
A constructor which creates and object by initializing it with an object of the same
class, which has been created previously.
*/
Fixed::Fixed(const Fixed& b) {
	raw = b.raw;
	std::cout << "Copy Constructor Called" << std::endl;
}

//Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}