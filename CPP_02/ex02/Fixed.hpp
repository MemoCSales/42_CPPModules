#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE	 	"\033[1;37m"
# define DEFAULT	"\033[0m"

class Fixed
{
	private:
		int fixPoint;
		static const int    number = 8;
	public:
		Fixed(void);
		Fixed(const int value);		//Integer constructor
		Fixed(const float value);	//Float constructor
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed &other);
		//Comparison operators
		bool operator>(const Fixed&other) const;
		bool operator<(const Fixed&other) const;
		bool operator>=(const Fixed&other) const;
		bool operator<=(const Fixed&other) const;
		bool operator==(const Fixed&other) const;
		bool operator!=(const Fixed&other) const;
		//Arithmetic operators
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		Fixed operator-(const Fixed &other) const;
		~Fixed();
		//Member functions
		float	toFloat(void) const;
		int		toInt(void)const;
		static Fixed& min(Fixed& a, Fixed&b);
		static const Fixed& min(const Fixed& a, const Fixed&b);
		static Fixed& max(Fixed& a, Fixed&b);
		static const Fixed& max(const Fixed& a, const Fixed&b);
};

std::ostream &operator<<(std::ostream &o, const Fixed &value);

#endif

