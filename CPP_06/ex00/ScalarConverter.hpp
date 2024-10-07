#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>
# include <math.h>
# include <cstdlib> //atoi
# include <climits> // probably not used
# include <limits>
# include <stdint.h>
# include <sstream>

# define DEBUG 0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT		"\033[0m"

class ScalarConverter {
	private:
		ScalarConverter(void);
	public:
		static void convert(const std::string& literal);
		
};


bool isChar(const std::string& lit);
bool isInt(const std::string& lit);
bool isFloat(const std::string& lit);
bool isDouble(const std::string& lit);

void printChar(const std::string& lit);
void printInt(const std::string& lit);
void printFloat(const std::string& lit);
void printDouble(const std::string& lit);
void printSpecialFloat(const std::string& lit);
void printSpecialDouble(const std::string& lit);

#endif
