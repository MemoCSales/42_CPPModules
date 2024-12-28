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
