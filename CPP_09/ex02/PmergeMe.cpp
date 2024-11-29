# include "PmergeMe.hpp"

// ++++Constructor
PmergeMe::PmergeMe(void) {
	if (DEBUG) {
		std::cout << "PmergeMe default constructor called" << std::endl;
	}
}

// ++++Constructor
// PmergeMe::PmergeMe("Parameters") {
// 	if (DEBUG) {
// 		std::cout << "PmergeMe parameter constructor called" << std::endl;
// 	}
// }

// Copy Constructor
// PmergeMe::PmergeMe(const PmergeMe &other) : "_variable(other._variable)"{
// 	if (DEBUG) {
// 		std::cout << "PmergeMe copy constructor called" << std::endl;
// 	}
// }

// Assignment Operator
// PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
// 	if (DEBUG) {
// 		std::cout << "PmergeMe Assignment Operator called" << std::endl;
// 	}
// 	if (this != &other) {
// 		// Copy data from other to this
// 	}
// 	return *this;
// }

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

bool PmergeMe::argsValidation(PmergeMe& obj, int argc, char** argv) {
	if (argc < 2) {
		return false;
	}
	for (size_t i = 1; argv[i] != NULL; i++) {
		int number = std::atoi(argv[i]);
		if (number <= 0) {
			return false;
		} else {
			obj.populateVector(number);
			obj.populateDeque(number);
		}
	}
	
	return true;
}

void PmergeMe::populateVector(int& number) {
	_myVector.push_back(number);
}

void PmergeMe::populateDeque(int& number) {
	_myDeque.push_back(number);
}


