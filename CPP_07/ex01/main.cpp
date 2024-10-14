#include "iter.hpp"

int main(void) {
	int arr[] = {1,2,3};
	int size = 3;

	::iter(arr, size, printElement<int>);
	std::cout << "Multiply each element of the int array by 2:" << std::endl;
	::iter(arr, size, multiplyElement);
	::iter(arr, size, printElement<int>);

	char array[] = {'a', 'b', 'c'};
	// int size = 3;
	std::cout << "Array of chars:" << std::endl;
	::iter(array, size, printElement);
	::iter(array, size, toUpper);

	return 0;
}
