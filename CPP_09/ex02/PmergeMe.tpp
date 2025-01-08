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

	if (isSorted(container)) 
		return;

	// Step 1: Divide into pairs and sort each pair
	T as; // Large elements
	T bs; // Small elements
	for (int i = 0; i < n - 1; i += 2)
	{
		if (container[i] > container[i + 1]) {
			as.push_back(container[i]);
			bs.push_back(container[i + 1]);
		} else {
			as.push_back(container[i + 1]);
			bs.push_back(container[i]);
		}
	}

	// Handling odd element
	if (n % 2 != 0) {
		as.push_back(container[n - 1]);
	}

	if (DEBUGSORT) {
		std::cout << "Large elements (as):" << std::endl;
		PmergeMe::printContainer(as);
		std::cout << "Small elements (bs):" << std::endl;
		PmergeMe::printContainer(bs);
	}

	// Debug print before recursive call
	if (DEBUGSORT) {
		std::cout << "As before:" << std::endl;
		printContainer(as);
	}

	// Recursion of Step 1
	fordJohnsonSort(as);

	// Debug print after recursive call
	if (DEBUGSORT) {
		std::cout << "As after:" << std::endl;
		printContainer(as);
	}

	if (DEBUGSORT) {
		std::cout << "Bs: " << std::endl;
		printContainer(bs);
	}

	// Step 2, 3, 4: Insertion
	// Starting from the 3rd Jacobsthal number
	int k = 3;
	// How many elements to work with so far
	// jacobsthal(k);
	// How many elements have already been inserted in previous steps
	// jacobsthal(k - 1);
	// The difference between current_jacobsthal and previous_jacobsthal tells you how many new elements to insert
	// jacobsthal(k) - jacobsthal(k - 1)
	while ((jacobsthal(k) - jacobsthal(k - 1)) <= static_cast<int>(bs.size()) ) {
		int newGroupSize = jacobsthal(k) - jacobsthal(k - 1);
		if (DEBUGSORT) std::cout << "Group size: " << newGroupSize << std::endl;
		for (int i = 0; i < newGroupSize && !bs.empty(); ++i) {
			if (DEBUGSORT) {
				std::cout << "As inside Jacobsthal: " << std::endl;
				printContainer(as);
			}
			binaryInsert(as, bs.back());
			bs.pop_back();
		}
		++k;
	}

	if (DEBUGSORT) {
		std::cout << "Bs elements after jacobsthal: " << std::endl;
		printContainer(bs);
	}

	while (!bs.empty()) {
		binaryInsert(as, bs.back());
		bs.pop_back();
	}

	if (DEBUGSORT) {
		std::cout << "As after odd elements is inserted: " << std::endl;
		printContainer(as);
	}

	// // Copy the sorted elements back to the original array
	container = as;
}