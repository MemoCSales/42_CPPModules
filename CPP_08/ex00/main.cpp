#include "easyfind.hpp"
#include <vector>

# define MAX_SIZE 50

int main () {
	std::vector<int> ejemplo(MAX_SIZE);

	srand(static_cast<unsigned int>(time(0)));
	int min = 1;
	int max = 100;

	for (std::vector<int>::iterator it = ejemplo.begin(); it != ejemplo.end(); it++)
	{
		*it = min + std::rand() % (max - min + 1);
	}

	// Table header
	std::cout << std::left << std::setw(10) << "Index" << std::setw(10) << "Value" << std::endl;
	std::cout << std::string(20, '-') << std::endl;

	for (std::vector<int>::size_type i = 0; i != ejemplo.size(); i++)
	{
        std::cout << std::left << std::setw(5) << i << " ->     " << std::setw(10) << ejemplo[i] << std::endl;
	}

	// int index = 0;

	// for (std::list<int>::iterator it = ejemplo.begin(); it != ejemplo.end(); ++it, index++)
	// {
    //     std::cout << std::left << std::setw(5) << index << " ->     " << std::setw(10) << *it << std::endl;
	// }
	
	
	try
	{
		int value = 42;
		std::cout << BLUE <<"Occurence to be found: " << DEFAULT << value << std::endl;
		std::vector<int>::iterator number = easyfind(ejemplo, value);
		std::cout << *number << ": " GREEN << "found in the container! " << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << '\n';
	}
	
	return 0;
}
