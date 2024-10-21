#include "easyfind.hpp"
#include <vector>
# include <list>

# define MAX_SIZE 50


void vectorTest() {
	std::vector<int> vectorTest(MAX_SIZE);

	srand(static_cast<unsigned int>(time(0)));
	int min = 1;
	int max = 100;

	for (std::vector<int>::iterator it = vectorTest.begin(); it != vectorTest.end(); it++)	{
		*it = min + std::rand() % (max - min + 1);
	}
	
	//Table header
	std::cout << GREEN << "TESTING WITH VECTOR" << DEFAULT << std::endl;
	std::cout << std::left << std::setw(10) << "Index" << std::setw(10) << "Value" << std::endl;
	std::cout << std::string(20, '-') << std::endl;
	for (std::vector<int>::size_type i = 0; i != vectorTest.size(); i++)	{
        std::cout << std::left << std::setw(5) << i << " ->     " << std::setw(10) << vectorTest[i] << std::endl;
	}
	try
	{
		int value = 42;
		std::cout << BLUE <<"Occurence to be found: " << DEFAULT << value << std::endl;
		std::vector<int>::iterator number = easyfind(vectorTest, value);
		std::cout << *number << ": " GREEN << "found in the container! " << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << '\n';
	}
	
}

void listTest() {
	std::list<int> listTest(MAX_SIZE);

	srand(static_cast<unsigned int>(time(0)));
	int min = 1;
	int max = 100;

	for (std::list<int>::iterator it = listTest.begin(); it != listTest.end(); it++)	{
		*it = min + std::rand() % (max - min + 1);
	}
	//Table header
	std::cout << GREEN << "TESTING WITH LIST" << DEFAULT << std::endl;
	std::cout << std::left << std::setw(10) << "Index" << std::setw(10) << "Value" << std::endl;
	std::cout << std::string(20, '-') << std::endl;
	int index = 0;

	for (std::list<int>::iterator it = listTest.begin(); it != listTest.end(); ++it, index++)	{
        std::cout << std::left << std::setw(5) << index << " ->     " << std::setw(10) << *it << std::endl;
	}
	try
	{
		int value = 42;
		std::cout << BLUE <<"Occurence to be found: " << DEFAULT << value << std::endl;
		std::list<int>::iterator number = easyfind(listTest, value);
		std::cout << *number << ": " GREEN << "found in the container! " << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << '\n';
	}

}

int main () {
	vectorTest();
	// listTest();
	
	return 0;
}
