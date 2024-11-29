#ifndef PmergeMe_HPP
# define PmergeMe_HPP
# include <iostream>
# include <sstream>
# include <cstdlib>
# include <vector>
# include <deque>

# define DEBUG 0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT		"\033[0m"


typedef std::deque<int>::const_iterator itDeque;
typedef std::vector<int>::const_iterator itVector;

class PmergeMe {
	private:
		std::vector<int> _myVector;
		std::deque<int> _myDeque;
	public:
		PmergeMe(void);
		~PmergeMe();

		// Getters
		std::vector<int>& getVector();
		std::deque<int>& getDeque();
		// Setters

		// Methods
		void populateVector(int& number);
		void populateDeque(int& number);
		
		static bool argsValidation(PmergeMe&, int, char**);

		template <typename T>
		static void printContainer(const T& container);
		template <typename T>
		void insertionSort(T& container);

};


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
void mergeSort(T& container, int left, int right) {
	// Base case
	
}

#endif
