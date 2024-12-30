# include "PmergeMe.hpp"

// ++++Constructor
PmergeMe::PmergeMe(void) {
	if (DEBUG) {
		std::cout << "PmergeMe default constructor called" << std::endl;
	}
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe& other) : _myVector(other._myVector), _myDeque(other._myDeque) {
	if (DEBUG) {
		std::cout << "PmergeMe copy constructor called" << std::endl;
	}
}

// Assignment operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_myVector = other._myVector;
		_myDeque = other._myDeque;
	}
	if (DEBUG) {
		std::cout << "PmergeMe assignment operator called" << std::endl;
	}
	return *this;
}

// ----Destructor
PmergeMe::~PmergeMe() {
	if (DEBUG) {
		std::cout << "PmergeMe destructor called" << std::endl;
	}
}

// Getters
std::vector<int>& PmergeMe::getVector() {
	return _myVector;
}

std::deque<int>& PmergeMe::getDeque() {
	return _myDeque;
}


// Methods

bool PmergeMe::validateArgs(int argc, char** argv) {
	if (argc < 2) {
		throw std::invalid_argument("Not enough arguments provided.");
	}
	for (size_t i = 1; argv[i] != NULL; i++) {
		char* end;
		long number = std::strtol(argv[i], &end, 10);
		if (*end != '\0') {
			throw std::invalid_argument("Argument is not a valid number: " + std::string(argv[i]));
		}
		if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max()) {
			throw std::out_of_range("Argument is out of integer range: " + std::string(argv[i]));
		}
		if (number <= 0) {
			throw std::invalid_argument("Argument must be a positive integer: " + std::string(argv[i]));
		}
	}
	return true;
}

void PmergeMe::populateVector(char** argv) {
	for (size_t i = 1; argv[i] != NULL; i++) {
		int number = std::atoi(argv[i]);
		_myVector.push_back(number);
	}
}

void PmergeMe::populateDeque(char** argv) {
	for (size_t i = 1; argv[i] != NULL; i++) {
		int number = std::atoi(argv[i]);
		_myDeque.push_back(number);
	}
}



// Functions outside the class

std::string argvToString(char **argv) {
	std::string str;
	for (size_t i = 1; argv[i] != NULL; i++) {
		str += toStr(argv[i]);
		str += " ";
	}
	return str;
}

long jacobsthal(int k) {
	if (k == 0) return 0;
	if (k == 1) return 1;
	return jacobsthal(k -1) + 2 * jacobsthal(k - 2);
}
