#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	fixPoint = 0;
}

//Int constructor
Fixed::Fixed(const int value) {
	// std::cout << GREEN << "Int constructor called" << DEFAULT << std::endl;
	fixPoint = value * 256;		//256 = 2^8
}

//Float constructor
Fixed::Fixed(const float value) {
	// std::cout << GREEN << "Float constructor called" << DEFAULT << std::endl;
	fixPoint = roundf(value * 256);
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator overload
// you're defining how that operator behaves when applied to objects of your class.
Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixPoint = other.fixPoint;
	return (*this);
}

//Compartison operators
bool Fixed::operator>(const Fixed& other) const {
	return (this->fixPoint > other.fixPoint);
}

bool Fixed::operator<(const Fixed& other) const {
	return (this->fixPoint < other.fixPoint);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (this->fixPoint >= other.fixPoint);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (this->fixPoint <= other.fixPoint);
}

bool Fixed::operator==(const Fixed& other) const {
	return (this->fixPoint == other.fixPoint);
}

bool Fixed::operator!=(const Fixed& other) const {
	return (this->fixPoint != other.fixPoint);
}


//Arithmetic operators
Fixed Fixed::operator*(const Fixed& other) const {
	Fixed	result;
	long long	temp = (this->fixPoint) * other.fixPoint;
	result.fixPoint = (temp >> number);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed	result;
	long long	temp = (this->fixPoint) / other.fixPoint;
	result.fixPoint = (temp >> number);
	return result;
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.fixPoint = this->fixPoint + other.fixPoint; 
	return result;
}

Fixed& Fixed::operator++() {
	++fixPoint;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed	temp = *this;
	operator++();
	// ++fixPoint;
	return temp;
}

Fixed& Fixed::operator--() {
	--fixPoint;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed	temp = *this;
	operator--();
	return temp;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.fixPoint = this->fixPoint - other.fixPoint; 
	return result;
}

// Destructor
Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
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

Fixed& Fixed::min(Fixed& a, Fixed&b) {
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed&b) {
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed&b) {
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed&b) {
	if (a > b)
		return a;
	return b;
}