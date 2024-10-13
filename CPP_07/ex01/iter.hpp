#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T> void printElement(const T& element) {
	std::cout << element << std::endl;
}

template <typename T> void iter(T *array, size_t size, void (*func)(const T&)) {
	for (size_t i = 0; i < size; i++) {
		func(array[i]);
	}
}

#endif
