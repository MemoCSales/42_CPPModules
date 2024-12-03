# include "PmergeMe.hpp"

template <typename T>
void PmergeMe::printContainer(const T& container) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void PmergeMe::printPairwiseContainer(const typename pairContainer<T>::type& container) {
	for (typename pairContainer<T>::type::const_iterator it = container.begin(); it != container.end(); it++) {
		std::cout << "{" << it->first << ", " << it->second << "} " << std::endl;
	}
}


template <typename T>
void PmergeMe::insertionSort(T& container) {
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		typename T::difference_type i = std::distance(container.begin(), it);
		int key = container[i];
		typename T::difference_type j = i - 1;

		/* Shift elements that are greater than key,
		to one position ahead of their current position
		it continuos as long as j is non-negative and the
		element at index j is greater than key */
		while (j >= 0 && container[j] > key) {
			container[j + 1] = container[j];
			j = j - 1;
		}
		/* Placing ey in its correct position in the sorted
		part of the container */
		container[j + 1] = key; 
	}
}

template <typename T>
void PmergeMe::insertionSortRecursive(T& container, int n) {
	// Base case
	if (n <= 1) {
		return ;
	}
	// Sort the first n-1 elements recursively
	insertionSortRecursive(container, n - 1);
	typename T::value_type key = container[n - 1];
	typename T::difference_type j = n - 2;

	// Shift elements that are greater than the key
	while (j >= 0 && container[j] > key) {
		container[j + 1] = container[j];
		j = j - 1;
	}
	container[j + 1] = key;
}

template <typename T>
typename pairContainer<T>::type PmergeMe::pairWise(const T& container) {
	typename pairContainer<T>::type pairedContainer;

	for (typename T::const_iterator it = container.begin(); it != container.end(); it++) {
		int first = *it;
		it++;
		int second = (it != container.end()) ? *it : 0; //todo: check this
		pairedContainer.push_back(std::make_pair(first, second));
	}
	return pairedContainer;
}

template <typename T>
void PmergeMe::separatePairs(typename pairContainer<T>::type& containerPairs, T& container, T& minContainer) {
	for (typename pairContainer<T>::type::iterator it = containerPairs.begin(); it != containerPairs.end(); it++) {
		if (it->first > it->second) {
			std::swap(it->first, it->second);
		}
		minContainer.push_back(it->first);
		container.push_back(it->second);
	}
}

template <typename T>
void PmergeMe::fordJohnsonAlgo(T& container) {
	// Split in pairs
	if (container.size() % 2 != 0) {
		int lastElement = container.back();
		container.pop_back();
		std::cout << "Last Element: " << lastElement << std::endl;
	}
	typename pairContainer<T>::type containerPairs = pairWise(container);
	PmergeMe::printPairwiseContainer<T>(containerPairs);

	// Clearing the original container
	container.clear();

	// Separate the pairs into min and max containers;
	T minContainer;
	PmergeMe::separatePairs(containerPairs, container, minContainer);
	PmergeMe::printPairwiseContainer<T>(containerPairs);

	// Printing min and max containers and sort max
	std::cout << "Min container: " << std::endl;
	PmergeMe::printContainer(minContainer);
	std::cout << "Max container/Main chain sorted: " << std::endl;
	PmergeMe::insertionSortRecursive(container, container.size());
	PmergeMe::printContainer(container);
	
}

