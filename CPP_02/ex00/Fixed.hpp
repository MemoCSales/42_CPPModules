#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
		int                 raw;
		static const int    number = 8;
	public:
		Fixed();								//Default constructor
		Fixed(const Fixed& b);					//Copy constructor
		~Fixed();								//Destructor
		Fixed &operator=(const Fixed& F);		//Copy assignment operator
		//Setters
		void    setRawBits(int const _raw);
		//Getters
		int     getRawBits(void) const;

};

#endif