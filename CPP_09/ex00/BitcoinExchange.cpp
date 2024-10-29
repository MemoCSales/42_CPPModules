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

			std::cout << "Date: " << dateString << ", Price: " << price << std::endl;
		}
	}
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
		}
		
	}
	inputFile.close();
	return 0;
}

