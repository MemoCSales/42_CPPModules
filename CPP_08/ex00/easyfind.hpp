#pragma once
# include <iostream>
# include <exception>
# include <cstdlib>
# include <algorithm>
# include <iomanip>


# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT		"\033[0m"


class NoOcurrenceFound : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Error: The value has not been found in the container");
		}
};

template <typename T> typename T::iterator easyfind(T &first, int value) {

	typename T::iterator it = std::find(first.begin(), first.end(), value);
	if (it != first.end())
		return it;
	else {
		throw NoOcurrenceFound();
	}
}


template <typename T> void iter(T *array, size_t size, void (*func)(T&)) {
	for (size_t i = 0; i < size; i++) {
		func(array[i]);
	}
}
