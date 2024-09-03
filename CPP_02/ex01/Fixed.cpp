#include "Fixed.hpp"

//Constructor
Fixed::Fixed () {
	std::cout << GREEN << "Default constructor called" << DEFAULT << std::endl;
}

//Int constructor
Fixed::Fixed(const int value) {
	std::cout << GREEN << "Int constructor called" << DEFAULT << std::endl;
	fixPoint = value * 256;		//256 = 2^8
}

//Float constructor
Fixed::Fixed(const float value) {
	std::cout << GREEN << "Float constructor called" << DEFAULT << std::endl;
	fixPoint = roundf(value * 256);
}

//Copy constructor
/* A constructor which creates and object by initializing it with an object of the same
class, which has been created previously. */
Fixed::Fixed(const Fixed& b) {
	std::cout << YELLOW << "Copy constructor called" << DEFAULT << std::endl;
	*this = b;
}

//Destructor
Fixed::~Fixed() {
	std::cout << RED << "Destructor called" << DEFAULT << std::endl;
}

//---------------------------------------------------------------------

//Getters
int     Fixed::getFixPoint(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return fixPoint;
}

//-----------------------------------------------------------------------

//Move Assignment Operator Overload
Fixed &Fixed::operator=(const Fixed& F) {
	std::cout << WHITE << "Copy assignment operator called" << DEFAULT << std::endl;
	if (this != &F)
		this->fixPoint = F.fixPoint;
	return *this;
}

//Output stream operator
std::ostream &operator<<(std::ostream &o, const Fixed &value) {
	o << value.toFloat();
	return (o);
}

//----------------------------------------------------------------------

//Member functions
float	Fixed::toFloat(void) const {
	return (fixPoint / 256.0);
}

int	Fixed::toInt(void) const {
	return (fixPoint / 256);
}