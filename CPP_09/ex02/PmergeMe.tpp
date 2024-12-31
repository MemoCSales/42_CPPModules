# include "PmergeMe.hpp"

template <typename T>
void PmergeMe::binaryInsert(T& main, int value) {
	int left = 0;
	int right = main.size();

	while (left < right) {
		int mid = left + (right - left) / 2;
		if (main[mid] < value) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}
	main.insert(main.begin() + left, value);
}

template <typename T>
void PmergeMe::fordJohnsonSort(T& container) {
	// base case
	int n = container.size();
	if (n <= 1) return;

	// Step 1: Divide into pairs and sort each pair
	std::vector<std::pair<typename T::value_type, typename T::value_type> > pairs;
	for (int i = 0; i < n - 1; i += 2)
	{
		if (container[i] > container[i + 1]) {
			pairs.push_back(std::make_pair(container[i + 1], container[i]));
		} else {
			pairs.push_back(std::make_pair(container[i], container[i + 1]));
		}
	}

	// Handling odd element
	if (n % 2 != 0) {
		pairs.push_back(std::make_pair(container[n - 1], INT_MAX_LIMIT));
	}

	if (DEBUGSORT) PmergeMe::printPairElements(pairs);

	// Step 2: Recursively sort the 'a' elements
	T main;
	typename std::vector<std::pair<typename T::value_type, typename T::value_type> >::iterator itMain = pairs.begin();
	for (; itMain != pairs.end(); ++itMain)
	{
		if ((*itMain).second != INT_MAX_LIMIT) {
			main.push_back((*itMain).second);
		}
	}

	// Debug print before recursive call
	if (DEBUGSORT) {
		std::cout << "main before:" << std::endl;
		printContainer(main);
	}

	// Recursion of Step 1
	fordJohnsonSort(main);

	// Debug print after recursive call
	if (DEBUGSORT) {
		std::cout << "main after:" << std::endl;
		printContainer(main);
	}
	
	// // Step 3: Insert 'b' elements into the main sequence using Jacobsthal order
	T pend;
	typename std::vector<std::pair<typename T::value_type, typename T::value_type> >::iterator itPend = pairs.begin();
	for (; itPend != pairs.end(); ++itPend) {
		if ((*itPend).first != INT_MAX_LIMIT) {
			pend.push_back((*itPend).first);
		}
	}

	if (DEBUGSORT) {
		std::cout << "pend: " << std::endl;
		printContainer(pend);
	}

	// // Starting from the 3rd Jacobsthal number
	int k = 3;
	// How many elements to work with so far
	int currentJ = jacobsthal(k);
	// How many elements have already been inserted in previous steps
	int previousJ = jacobsthal(k - 1);
	// The difference between current_jacobsthal and previous_jacobsthal tells you how many new elements to insert
	size_t newElementsToInsert = static_cast<size_t>(currentJ - previousJ);
	while (newElementsToInsert <= pend.size()) {
		int count = newElementsToInsert;
		if (DEBUGSORT) std::cout << "New Elements to insert: " << count << std::endl;
		for (int i = 0; i < count; ++i) {
			if (DEBUGSORT) {
				std::cout << "main inside Jacobsthal: " << std::endl;
				printContainer(main);
			}
			binaryInsert(main, pend.back());
			pend.pop_back();
		}
		++k;
	}

	if (DEBUGSORT) {
		std::cout << "pend elements after jacobsthal: " << std::endl;
		printContainer(pend);
	}
	// If newElementsToInsert is bigger than the size of pend, then insert the remaining numbers using binarySearch
	while (!pend.empty()) {
		binaryInsert(main, pend.back());
		pend.pop_back();
	}

	if (DEBUGSORT) {
		std::cout << "main after checking pend elements binaryInsert: " << std::endl;
		printContainer(main);
	}

	// // Copy the sorted elements back to the original array
	for (int i = 0; i < n; ++i) {
		container[i] = main[i];
	}
}