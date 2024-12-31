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
