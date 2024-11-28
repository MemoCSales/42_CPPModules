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
		// PmergeMe("Parameter Constructor");
		// PmergeMe(const PmergeMe &other);
		// PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		// Getters
		const std::vector<int>& getVector() const;
		const std::deque<int>& getDeque() const;
		// Setters

		// Methods
		void populateVector(int& number);
		void populateDeque(int& number);

		static bool argsValidation(PmergeMe&, int, char**);
};

#endif
