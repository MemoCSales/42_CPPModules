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


// ---------- Methods ------------
bool BitcoinExchange::dataBaseManagement() {
	std::ifstream dataBase("data.csv");
	std::string line;

	if (!(dataBase.is_open())) {
		std::cerr << ERROR_MESSAGE << std::endl;
		return false;
	} else {
		if (std::getline(dataBase, line)) {}
		while (std::getline(dataBase, line)) {
			std::istringstream ss(line);
			std::string dateString, priceString;
				if (std::getline(ss, dateString, ',') && std::getline(ss, priceString, ',')) {
					float price = std::atof(priceString.c_str());

					_bitcoin.insert(std::make_pair(dateString, price));
				}
			}
		}
	return true;
}


void BitcoinExchange::findDateMatching(std::string& date, std::string& value, float& price) {
	std::map<std::string, float>::iterator it = iteratorCheck(date);
	float result = it->second * price;
	std::cout << "✅ Date: " << date << " => " << value << " = " << result << std::endl;
}


int BitcoinExchange::fileManagement(char** argv) {
	std::ifstream inputFile(argv[1], std::ifstream::in);
	std::string line;
	std::string dateString, valueString;
	float price;

	if (!(inputFile.is_open())) {
		std::cerr << ERROR_MESSAGE << std::endl;
		return 1;
	} else {
		// Skips header table
		if (std::getline(inputFile, line)) {}
		while (std::getline(inputFile, line)) {
			// Parsing the line to extract date and value. Skips the line if any error or exception is found
			if (!parseLine(dateString, valueString, line, price)) {
				continue;
			}
			findDateMatching(dateString, valueString, price);
		}
	}

	inputFile.close();
	return 0;
}


std::map<std::string, float>::iterator 
BitcoinExchange::iteratorCheck(const std::string& str) {
	for (std::map<std::string, float>::iterator itBegin = _bitcoin.begin(); itBegin != _bitcoin.end(); itBegin++)
	{
		if (itBegin->first == str) return itBegin;
		if (itBegin->first > str) {
			if (itBegin == _bitcoin.begin()) {
				return itBegin;
			} else {
				return --itBegin;
			}
		}
	}
	return _bitcoin.end();
}


// ---------- Functions ----------
void validateArgs(int argc) {
	if (argc != 2) {
		std::cerr << ERROR_MESSAGE << std::endl;
		exit(EXIT_FAILURE);
	}
}

bool stringHasDigits(const std::string& str) {
	std::cout << "Line checked: " << str << std::endl;
	for (size_t i = 0; i < str.size(); i++) {
		if (std::isdigit(str[i])) {
			return true;
		}
	}
	return false;
}

void trim(std::string& str) {
	str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
	str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
}

bool BitcoinExchange::parseLine(std::string &dateString, std::string &valueString, std::string &line, float &price) {

	try	{
		std::istringstream ss(line);

		if (std::getline(ss, dateString, '|')) {
			trim(dateString);
			if (std::getline(ss, valueString, '|')) {
				trim(valueString);
			} else {
				valueString = '\0';
			}
		}
		price = parseNumber(valueString);

		if (!isValidDate(dateString)) {
			std::cerr << "💀 Error: bad input => " << dateString << std::endl;
			return false;
		}
		if (!price) {
			throw InvalidValue();
			return false;
		}
		return true;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return false;
	}
}

float parseNumber(const std::string& str) {
	std::stringstream ss(str);
	float result;
	ss >> result;

	// Check if  the stream has failed or are any remaining characters in the input string
	if (ss.fail() || !ss.eof()) {
		throw InvalidValue();
	}

	if (result < 0.0f) throw NegativeValue();
	if (result > 1000.0f) throw MaxValue();

	return result;
}


bool BitcoinExchange::isValidDate(std::string& dateString) {
	// Parsing date and check if its valid or not
	std::map<std::string, float>::iterator itBegin = _bitcoin.begin();
	std::map<std::string, float>::iterator itEnd = _bitcoin.end();

	if (itEnd != _bitcoin.begin()) {
		--itEnd;
	}
	// Check input date is within the boundries of database
	if (dateString < itBegin->first || dateString > itEnd->first) return false;
	std::istringstream ss1(dateString);
	int day, month, year = 0;
	std::string dayString, monthString, yearString;
	
	if (std::getline(ss1,yearString, '-') && std::getline(ss1, monthString, '-') && std::getline(ss1, dayString, '-')) {
		year = std::atoi(yearString.c_str());
		month = std::atoi(monthString.c_str());
		day = std::atoi(dayString.c_str());
	} else {
		return false;
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
