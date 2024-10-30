#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP
# include <iostream>
# include <cstdlib>
# include <fstream>
# include <sstream>
# include <limits.h>
# include <map>

# define DEBUG 0
# define MAX_VALID_YR 9999
# define MIN_VALID_YR 1800
# define ERROR_MESSAGE "Error: could not open file."

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT		"\033[0m"


union IntFloatUnion {
	int intValue;
	float floatValue;
};

struct IntFloat {
	IntFloatUnion value;
	bool isFloat;
};


class BitcoinExchange {
	private:
		std::map<std::string, float> _bitcoin;
	public:
		BitcoinExchange(void);
		// BitcoinExchange("Parameter Constructor");
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

};

#endif

void validateArgs(int argc);
int fileManagement(char** argv);
bool stringHasDigits(const std::string& str);
void parseLine(std::string &dateString, std::string &valueString, std::string &line);
bool isValidDate(std::string& dateString);
bool isYearLeap(int year);
IntFloat parseNumber(const std::string& str);


// Exceptions
class NegativeValue : public std::exception {
	public:
	virtual const char* what() const throw() {
		return ("Error: not a positive number.");
	}
};
class MaxIntValue : public std::exception {
	public:
	virtual const char* what() const throw() {
		return ("Error: too large a number.");
	}
};

class MinIntValue : public std::exception {
	public:
	virtual const char* what() const throw() {
		return ("Error: not a positive number.");
	}
};

// #include "BitcoinExchange.hpp"



// // ++++Constructor
// BitcoinExchange::BitcoinExchange("Parameters") {
// 	if (DEBUG) {
// 		std::cout << "BitcoinExchange parameter constructor called" << std::endl;
// 	}
// }



