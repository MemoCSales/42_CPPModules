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


// -------My own implementation-------------------
template <typename Container, typename Function>
void iter(Container& container, Function func) {
	size_t index = 0;
	for (typename Container::iterator it = container.begin(); it != container.end(); it++, index++) {
		func(index, *it);
	}
}

template <typename T> void populateContainer(T& element, int min, int max) {
	srand(static_cast<unsigned int>(time(0)));
	for (typename T::iterator it = element.begin(); it != element.end(); it++)
	{
		*it = min + std::rand() % (max - min + 1);
	}
}

template <typename T> void printIndexAndValue(size_t index, int value) {
	std::cout << std::left << std::setw(5) << index << "  ->   " << std::setw(10) << value << std::endl;
}
