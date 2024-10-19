#include "easyfind.hpp"
#include <vector>

int main () {
	std::vector<int> ejemplo;

	for (int i = 1; i <= 5; i++)
	{
		ejemplo.push_back(i);
	}

	std::cout << "Vector elements are: " << std::endl;
	for (std::vector<int>::iterator it = ejemplo.begin(); it != ejemplo.end(); it++)
	{
		std::cout << *it << " ";
	}
	
	
	return 0;
}
