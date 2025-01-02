# include "PmergeMe.hpp"

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


/* Debugging function to print the pairs of elements */
void PmergeMe::printPairElements(const std::vector<std::pair<int, int> >& pairs) {
	std::vector<std::pair<int, int > >::const_iterator it = pairs.begin();
	for (; it != pairs.end(); ++it) {
		std::cout << "(" << it->first << ", " << it->second << ") ";
	}
	std::cout << std::endl;
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


/* Function that returns the k-th Jacobsthal number */
long jacobsthal(int k) {
	if (k == 0) return 0;
	if (k == 1) return 1;
	return jacobsthal(k -1) + 2 * jacobsthal(k - 2);
}

