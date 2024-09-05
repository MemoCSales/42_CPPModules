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
		int					fixPoint;
	public:
		Fixed();							//Default constructor
		Fixed(const int value);				//Integer constructor
		Fixed(const float value);			//Float constructor
		Fixed(const Fixed& b);				//Copy constructor
		~Fixed();							//Destructor
		Fixed &operator=(const Fixed& F);	//Assignment operator overload
		//Getters
		int     getFixPoint(void) const;
		//Member functions
		float	toFloat(void) const;
		int		toInt(void)const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &value);

#endif