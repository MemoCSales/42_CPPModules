#include "iter.hpp"

int main(void) {
	int arr[] = {1,2,3};
	int size = 3;

	std::cout << GREEN << "ARRAY OF INTEGERS: " << DEFAULT << std::endl;
	::iter(arr, size, printElement<int>);
	std::cout << GREEN << "MULTIPLY EACH ELEMENT BY 2:" << DEFAULT << std::endl;
	::iter(arr, size, multiplyElement);
	::iter(arr, size, printElement<int>);

	char array[] = {'a', 'b', 'c'};
	// int size = 3;
	std::cout << GREEN << "ARRAY OF CHARS:" << DEFAULT << std::endl;
	::iter(array, size, printElement);
	::iter(array, size, toUpper);
	::iter(array, size, printElement);

	std::cout << GREEN << "ARRAY OF STRINGS:" << DEFAULT << std::endl;
	std::string arrayStr[] = {"Hola", "42", "adios"};
	::iter(arrayStr, size, toUpperString);
	::iter(arrayStr, size, printElement);
	::iter(arrayStr, size, toLowerString);
	::iter(arrayStr, size, printElement);


	return 0;
}
