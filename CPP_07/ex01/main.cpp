#include "iter.hpp"

int main(void) {
	int arr[] = {1,2,3};
	int size = 3;

	::iter(arr, size, printElement<int>);

	return 0;
}
