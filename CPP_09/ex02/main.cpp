# include "PmergeMe.hpp"

int main(int argc, char **argv) {
	
	PmergeMe obj;
	if (!PmergeMe::argsValidationAndPopulate(obj, argc, argv)) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	
	/* printing Deque*/
	// std::cout << "Deque: ";
	// for (itDeque it = obj.getDeque().begin(); it != obj.getDeque().end(); it++) {
	// 	std::cout << *it << " ";
	// }

	// /* printing Vector */
	// std::cout << "\nVector: ";
	// for (itVector it = obj.getVector().begin(); it != obj.getVector().end(); it++) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	
	std::cout << "Print deque: " << std::endl;
	PmergeMe::printContainer(obj.getDeque());
	std::cout << "Print vector: " << std::endl;
	PmergeMe::printContainer(obj.getVector());
	return 0;
}
