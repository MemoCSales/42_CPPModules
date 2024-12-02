# include "PmergeMe.hpp"

template <typename T>
void PmergeMe::printContainer(const T& container) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
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
typename pairContainer<T>::type PmergeMe::pairWise(const T& container) {
	typename pairContainer<T>::type pairedContainer;

	for (typename T::const_iterator it = container.begin(); it != container.end(); it++) {
		int first = *it;
		it++;
		int second = (it != container.end()) ? *it : 0;
		pairedContainer.push_back(std::make_pair(first, second));
	}
	return pairedContainer;
}

template <typename T>
void PmergeMe::fordJohnsonAlgo(T& container) {
	// Part 1: Split in pairs and sorting
	if (container.size() % 2 != 0) {
		int lastElement = container.back();
		std::cout << "Last Element: " << lastElement << std::endl;
	}
	typename pairContainer<T>::type containerPairs = pairWise(container);
}

