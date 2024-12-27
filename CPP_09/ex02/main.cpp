# include "PmergeMe.hpp"

int main(int argc, char **argv) {
	
	PmergeMe obj;
	if (!PmergeMe::argsValidationAndPopulate(obj, argc, argv)) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	
	/* printing Deque*/
	std::cout << "Deque: ";
	for (itDeque it = obj.getDeque().begin(); it != obj.getDeque().end(); it++) {
		std::cout << *it << " ";
	}

	/* printing Vector */
	std::cout << "\nVector: ";
	for (itVector it = obj.getVector().begin(); it != obj.getVector().end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	// obj.fordJohnsonAlgo(obj.getDeque());
	// obj.fordJohnsonAlgo(obj.getVector());
	// obj.insertionSort(obj.getDeque());
	// std::cout << "Print deque: " << std::endl;
	// PmergeMe::printContainer(obj.getDeque());
	// obj.insertionSort(obj.getVector());
	// std::cout << "Print vector: " << std::endl;
	// PmergeMe::printContainer(obj.getVector());
	// std::cout << "Pairwise Deque: " << std::endl;
	// PmergeMe::printPairwiseContainer<std::deque<int> >(obj.pairWise(obj.getDeque()));

	return 0;
}
