#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP
# include <iostream>
# include <cstdlib>
# include <fstream>
# include <sstream>
# include <limits.h>
# include <algorithm>
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

class BitcoinExchange {
	private:
		std::map<std::string, float> _bitcoin;
	public:
		BitcoinExchange(void);
		// BitcoinExchange("Parameter Constructor");
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		// Method
		bool dataBaseManagement();
		int fileManagement(char** argv);
		void findDateMatching(std::string&, std::string&, float&);
		std::map<std::string, float>::iterator iteratorCheck(const std::string& str);
		bool isValidDate(std::string& dateString);
		bool parseLine(std::string &dateString, std::string &valueString, std::string &line, float& price);
		// Exceptions
		class DateOutOfBounds : public std::exception {
			public:
			virtual const char* what() const throw() {
				return ("❌ Error: Date has not been found in DataBase. ");
			}
		};

};

// Exceptions
class NegativeValue : public std::exception {
	public:
	virtual const char* what() const throw() {
		return ("❌ Error: not a positive number.");
	}
};
class MaxValue : public std::exception {
	public:
	virtual const char* what() const throw() {
		return ("❌ Error: too large a number.");
	}
};

class MinIntValue : public std::exception {
	public:
	virtual const char* what() const throw() {
		return ("❌ Error: not a positive number.");
	}
};

class InvalidValue : public std::exception {
	public:
	virtual const char* what() const throw() {
		return ("❌ Error: Invalid value. ");
	}
};

#endif

void validateArgs(int argc);
bool stringHasDigits(const std::string& str);
void trim(std::string& str);
float parseNumber(const std::string& str);
bool isYearLeap(int year);
