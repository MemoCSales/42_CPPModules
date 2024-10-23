#ifndef Span_HPP
# define Span_HPP
# include <iostream>
# include <vector>
# include <algorithm>
# include <limits.h>
# include <cstdlib>
# include <set>



# define DEBUG 0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT	"\033[0m"

class Span {
	private:
		unsigned int _N;
		std::vector<int> _numbers;
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		// Methods
		void addNumber(int value);
		int shortestSpan();
		int longestSpan();
		void printNumbers() const;
		void populateVector(int, int);
		// Exceptions
		class MaximumCapacity : public std::exception {
		public:
			virtual const char* what() const throw() {
				return ("Vector has reached its maximum capacity");
			}
		};
		class SpanError : public std::exception {
			public:
			virtual const char* what() const throw() {
				return ("Vector needs to have at least 2 numbers, please check");
			}
		};
};

#endif
