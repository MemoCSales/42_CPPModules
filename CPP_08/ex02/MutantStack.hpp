#pragma once
# include <iostream>
# include <stack>

# define DEBUG 0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT	"\033[0m"

template <typename T>
class MutantStack : public std::stack<T> {
	// protected:
	// 	std::deque<T> _c;
	public:
		MutantStack(void);
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack();
		// Defining iterators types
		typedef typename std::stack<T>::container_type::iterator iterator;				// during iterations elements can be modify
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;	// during iteration elements can not be modified
		// Implementations of iterators
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};

// Include template definition
# include "MutantStack.tpp"
