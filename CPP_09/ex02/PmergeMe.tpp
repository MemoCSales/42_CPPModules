# include "PmergeMe.hpp"

template <typename T>
void PmergeMe::printContainer(const T& container) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

/**
 * @brief Converts an integer value to a string.
 * 
 * @param value The integer value to be converted.
 * @return std::string The string representation of the integer value.
 */
template <typename T>
std::string toStr(T const& value)
{
	std::ostringstream ss;
	ss << std::fixed << value;
	return ss.str();
}

template <typename T>
void PmergeMe::fordJohnsonSort(T& container) {
	// base case
	int n = container.size();
	if (n <= 1) return;

	// Step 1: Divide into pairs and sort each pair
	std::vector<std::pair<int, int> > pairs;
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
		pairs.push_back(std::make_pair(container[n - 1], INT_MAX));
	}

	PmergeMe::printPairElements(pairs);

	// Step 2: Recursively sort the 'a' elements
	std::vector<int> main;
	std::vector<std::pair<int, int> >::iterator it = pairs.begin();
	for (; it != pairs.end(); ++it)
	{
		if ((*it).second != INT_MAX) {
			main.push_back((*it).second);
		}
	}

	// Debug print before recursive call
	std::cout << "main before:" << std::endl;
	printContainer(main);

	fordJohnsonSort(main);

	// Debug print after recursive call
	std::cout << "main after:" << std::endl;
	printContainer(main);
	/*...*/
	
	
	
}