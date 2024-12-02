# include "PmergeMe.hpp"

// ++++Constructor
PmergeMe::PmergeMe(void) {
	if (DEBUG) {
		std::cout << "PmergeMe default constructor called" << std::endl;
	}
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

bool PmergeMe::argsValidationAndPopulate(PmergeMe& obj, int argc, char** argv) {
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
