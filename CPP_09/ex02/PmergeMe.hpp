#ifndef PmergeMe_HPP
# define PmergeMe_HPP
# include <iostream>

# define DEBUG 0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT		"\033[0m"

class PmergeMe {
	private:
	
	public:
		PmergeMe(void);
		// PmergeMe("Parameter Constructor");
		// PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
};

#endif

// #include "PmergeMe.hpp"

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
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (DEBUG) {
		std::cout << "PmergeMe Assignment Operator called" << std::endl;
	}
	if (this != &other) {
		// Copy data from other to this
	}
	return *this;
}

// ----Destructor
PmergeMe::~PmergeMe() {
	if (DEBUG) {
		std::cout << "PmergeMe destructor called" << std::endl;
	}
}
