#ifndef PmergeMe_HPP
# define PmergeMe_HPP
# include <iostream>
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include <vector>
# include <deque>
# include <ctime>
# include <limits>
# include <climits>
# include <utility>

# define DEBUG 0
# define DEBUGSORT 0

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
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		// Getters
		std::vector<int>& getVector();
		std::deque<int>& getDeque();
		// Setters

		// Methods
		void populateVector(char** argv);
		void populateDeque(char** argv);
		
		bool validateArgs(int argc, char** argv);

		static void printPairElements(const std::vector<std::pair<int, int> >& pairs); 
		
		// Template Methods
		template <typename T>
		static void printContainer(const T& container);
		template <typename T>
		static void fordJohnsonSort(T& container);
		template <typename T>
		static void binaryInsert(T& main, int value);
		template <typename T>
		static bool isSorted(const T& container);
};


std::string argvToString(char **argv);
long	jacobsthal(int k);

template <typename T>
std::string toStr(T const& value);

# include "PmergeMe.tpp"
# include "Utils.tpp"

#endif
