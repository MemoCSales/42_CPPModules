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


// Type trait to determine the appropriate type of container for the pairs
template <typename T>
struct pairContainer;

template <>
struct pairContainer<std::vector<int> > {
	using type = std::vector<std::pair<int, int>>;
};

template <>
struct pairContainer<std::deque<int> > {
	using type = std::deque<std::pair<int, int>>;
};

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
		
		static bool argsValidationAndPopulate(PmergeMe&, int, char**);
		
		// Template Methods
		template <typename T>
		static void printContainer(const T& container);
		template <typename T>
		void insertionSort(T& container);
		template <typename T>
		void fordJohnsonAlgo(T& container);
		template <typename T>
		typename pairContainer<T>::type pairWise(const T& container);

};

# include "PmergeMe.tpp"

#endif
