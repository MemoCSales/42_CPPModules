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

/* There traits use template specialization to determine if a given type
 is a vector or deque */
 template <typename T>
 struct isVector {
	static const bool value = false;
 };

 template <typename T>
 struct isVector<std::vector<T> > {
	static const bool value = true;
 };

  template <typename T>
 struct isDeque {
	static const bool value = false;
 };

 template <typename T>
 struct isDeque<std::deque<T> > {
	static const bool value = true;
 };

 template <typename T, bool itIsVector = isVector<T>::value, bool itIsDeque = isDeque<T>::value>
 struct pairContainer;

/* This trait uses SFINAE to select appropriate container type based on the results
of the isVector and isDeque traits */
 template <typename T>
 struct pairContainer<T, true, false> {
	typedef std::vector<std::pair<typename T::value_type, typename T::value_type> > type;
 };

 template <typename T>
 struct pairContainer<T, false, true> {
	typedef std::deque<std::pair<typename T::value_type, typename T::value_type> > type;
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
		static void printPairwiseContainer(const typename pairContainer<T>::type& container);
		template <typename T>
		void insertionSort(T& container);
		template <typename T>
		void insertionSortRecursive(T& container, int n);
		template <typename T>
		void separatePairs(typename pairContainer<T>::type&, T&, T&);
		template <typename T>
		void fordJohnsonAlgo(T& container);
		template <typename T>
		typename pairContainer<T>::type pairWise(const T& container);

};

# include "PmergeMe.tpp"

#endif
