# include "PmergeMe.hpp"

int main(int argc, char **argv) {
	
	try
	{
		PmergeMe obj;
		if (!obj.validateArgs(argc, argv)) {
			std::cerr << "Error: Invalid arguments" << std::endl;
			return 1;
		}

		std::string unsorted = argvToString(argv);

		// VECTOR
		clock_t startVector = clock();
		obj.populateVector(argv);
		// Add sorting algorithm here
		PmergeMe::fordJohnsonSort(obj.getVector());
		clock_t endVector = clock();
		double executionTimeVector = (double)(endVector - startVector) / CLOCKS_PER_SEC;
		bool sorted = PmergeMe::isSorted(obj.getVector());
		if (DEBUG) {
			if (sorted) {
				std::cout << "Vector SORTED!" << std::endl;
			} else {
				std::cout << "Vector NOT SORTED :(" << std::endl;
			}
		}
		// DEQUE
		clock_t startDeque = clock();
		obj.populateDeque(argv);
		// Add sorting algorithm here
		PmergeMe::fordJohnsonSort(obj.getDeque());
		clock_t endDeque = clock();
		double executionTimeDeque = (double)(endDeque- startDeque) / CLOCKS_PER_SEC;
		bool sortedDeque = PmergeMe::isSorted(obj.getDeque());
		if (DEBUG) {
			if (sortedDeque) {
				std::cout << "Deque SORTED!" << std::endl;
			} else {
				std::cout << "Deque NOT SORTED :(" << std::endl;
			}
		}

		// RESULTS
		std::cout << RED << "Before: " << DEFAULT;
		std::cout << unsorted << std::endl;
		std::cout << GREEN <<"After:  " << DEFAULT;
		PmergeMe::printContainer(obj.getVector());
		std::cout << "Time to process a range of " <<  WHITE << obj.getVector().size() << DEFAULT
				  << " elements with " << MAGENT << "std::vector: " << DEFAULT << std::fixed << std::setprecision(6)
				  << executionTimeVector << "s" << std::endl;
		std::cout << "Time to process a range of " << WHITE << obj.getVector().size() << DEFAULT
				  << " elements with " << CYAN << "std::deque: " << DEFAULT << std::fixed << std::setprecision(6)
				  << executionTimeDeque << "s" << std::endl;

		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	
}
