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
	// Debug printing
	for(std::map<std::string, float>::iterator i = _bitcoin.begin(); i != _bitcoin.end(); i++) {
		std::cout << i->first << " -> " << i->second << std::endl;
	}
	std::cout << "Size of my map: "<<  _bitcoin.size() << std::endl;

	return true;
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

void parseLine(std::string &dateString, std::string &valueString, std::string &line, float &price) {

	try	{
		std::istringstream ss(line);
		// float value;

		if (std::getline(ss, dateString, '|')) {
			// std::cout << "Date: " << dateString;
			if (std::getline(ss, valueString, '|')) {
				// value = std::atof(valueString.c_str());
				// std::cout << ", Price: " << valueString << std::endl;
			} else {
				valueString = '\0';
				// std::cout << ", Price: " << valueString << std::endl;
			}
		}
		// std::cout << "value: " << valueString << std::endl;
		price = parseNumber(valueString);
		// price = value;

		if (!isValidDate(dateString)) {
			std::cerr << "Error: bad input => " << dateString << std::endl;
		}
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}

float parseNumber(const std::string& str) {
	float result = std::stof(str.c_str());

	if (result < 0.0f) throw NegativeValue();
	if (result > 1000.0f) throw MaxValue();

	return result;
}


bool isValidDate(std::string& dateString) {
// Parsing date and check if its valid or not
	std::istringstream ss1(dateString);
	int day, month, year = 0;
	std::string dayString, monthString, yearString;
	
	if (std::getline(ss1,yearString, '-') && std::getline(ss1, monthString, '-') && std::getline(ss1, dayString, '-')) {
		year = std::atoi(yearString.c_str());
		month = std::atoi(monthString.c_str());
		day = std::atoi(dayString.c_str());
		// return true;
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


int BitcoinExchange::fileManagement(char** argv) {
	std::ifstream inputFile(argv[1], std::ifstream::in);
	std::string line;
	std::string dateString, valueString;
	float price;

	if (!(inputFile.is_open())) {
		std::cerr << ERROR_MESSAGE << std::endl;
		return 1;
	} else {
		if (std::getline(inputFile, line)) {}
		while (std::getline(inputFile, line)) {
			// Parsing the line to extract date and value
			parseLine(dateString, valueString, line, price);
			std::map<std::string, float>::iterator it = _bitcoin.find(dateString);
			// if (it != _bitcoin.end()) {

			// }
		}
	}

	inputFile.close();
	return 0;
}

