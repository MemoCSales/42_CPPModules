#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <cctype>

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT		"\033[0m"


template <typename T> void printElement(T& element) {
	std::cout << element << std::endl;
}

template <typename T> void multiplyElement(T& element) {
	element *= 2;
}

template <typename T> void iter(T *array, size_t size, void (*func)( T&)) {
	for (size_t i = 0; i < size; i++) {
		func(array[i]);
	}
}

// ---------- Callback chars functions ------------
template <typename T> void toUpper(T& element) {
	element = std::toupper(static_cast<int>(element));
}

void toUpperString(std::string& str) {
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = std::toupper(static_cast<int>(str[i]));
	}
	
}

void toLowerString(std::string &str) {
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = std::tolower(static_cast<int>(str[i]));
	}
	
}

#endif
