#pragma once
# include <iostream>
# include <exception>
# include <cstdlib>


# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT		"\033[0m"

template <typename T> 
class Array {
	private:
		T* _elements;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();
		T& operator[](int);
		// Exceptions
		class ArrayOutOfBounds : public std::exception {
			public:
				virtual const char* what() const throw () {
					return ("Array is out of bounds.");
				}
		};
		// Methods
		size_t size() const;
};

// Include template definition
# include "Array.tpp"