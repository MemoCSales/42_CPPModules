#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

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
template <typename T> void toUpper(char& element) {
	element = std::toupper(char& element);
}

#endif
