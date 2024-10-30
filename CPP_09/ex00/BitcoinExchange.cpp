# include "BitcoinExchange.hpp"

// ++++Constructor
BitcoinExchange::BitcoinExchange(void) : _bitcoin() {
	if (DEBUG) {
		std::cout << "BitcoinExchange default constructor called" << std::endl;
	}
}

// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	if (DEBUG) {
		std::cout << "BitcoinExchange copy constructor called" << std::endl;
	}
	this->_bitcoin = other._bitcoin;
}

// Assignment Operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (DEBUG) {
		std::cout << "BitcoinExchange Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		this->_bitcoin = other._bitcoin;
	}
	return *this;
}

// ----Destructor
BitcoinExchange::~BitcoinExchange() {
	if (DEBUG) {
		std::cout << "BitcoinExchange destructor called" << std::endl;
	}
}

// ---------- Functions ----------
void validateArgs(int argc) {
	if (argc != 2) {
		std::cerr << ERROR_MESSAGE << std::endl;
		exit(EXIT_FAILURE);
	}
}

bool stringHasDigits(const std::string& str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (std::isdigit(str[i])) {
			return true;
		}
	}
	return false;
}

void parseLine(std::string &dateString, std::string &valueString, std::string &line) {
	std::istringstream ss(line);

	if (std::getline(ss, dateString, '|')) {
		if (std::getline(ss, valueString, '|')) {
			float price = std::atof(valueString.c_str());
			// std::cout << "Date: " << dateString << ", Price: " << price << std::endl;
			(void)price;
		}
	}

	if (!isValidDate(dateString)) {
		std::cerr << "Error: bad input => " << dateString << std::endl;
	}
	
}

bool isValidDate(std::string& dateString) {
// Parsing date and check if its valid or not
	std::istringstream ss1(dateString);
	int day, month, year = 0;
	std::string dayString, monthString, yearString;
	if (std::getline(ss1, dayString, '-')) {
		if (std::getline(ss1, monthString, '-')) {
			if (std::getline(ss1, yearString, '-')) {
				day = std::atoi(dayString.c_str());
				month = std::atoi(monthString.c_str());
				year = std::atoi(yearString.c_str());
				// std::cout << "Day = " << day << std::endl;
				// std::cout << "Month = " << month << std::endl;
				// std::cout << "Year = " << year << std::endl;
			}
		}
	}
	// Check valid year
	if (year > MAX_VALID_YR || year < MIN_VALID_YR) return false;
	// Check valid month
	if (month < 1 || month > 12) return false;
	// Check valid day
	if (day < 1 || day > 31) return false;

	// Handle February month with leap year
	if (month == 2) {
		if (isYearLeap(year)) 
			return (day <= 29);
		else
			return (day <= 28);
	}

	// Handle months with 30 days
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day <= 30);
	
	return true;
}

bool isYearLeap(int year) {
	return(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

int fileManagement(char** argv) {
	std::ifstream inputFile(argv[1], std::ifstream::in);
	std::string line;
	std::string dateString, valueString;

	if (!(inputFile.is_open())) {
		std::cerr << ERROR_MESSAGE << std::endl;
		return 1;
	}

	while (std::getline(inputFile, line)) {
		if (stringHasDigits(line)) {
			// std::cout << "Line: " << line << std::endl;
			parseLine(dateString, valueString, line);
			// std::cout << "Date: " << dateString << std::endl;
			// std::cout << "Price: " << valueString << std::endl;
		}		
	}
	inputFile.close();
	return 0;
}

