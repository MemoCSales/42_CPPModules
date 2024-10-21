#include "easyfind.hpp"
#include <vector>
# include <list>

# define MAX_SIZE 50


void vectorTest() {
	std::vector<int> vectorTest(MAX_SIZE);

	srand(static_cast<unsigned int>(time(0)));
	int min = 1;
	int max = 100;

	populateContainer(vectorTest, min, max);
	//Table header
	std::cout << GREEN << "TESTING WITH VECTOR" << DEFAULT << std::endl;
	std::cout << std::left << std::setw(10) << "Index" << std::setw(10) << "Value" << std::endl;
	std::cout << std::string(20, '-') << std::endl;

	iter(vectorTest, printIndexAndValue<int>);
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
	int min = 1;
	int max = 100;

	populateContainer(listTest, min, max);
	//Table header
	std::cout << GREEN << "TESTING WITH LIST" << DEFAULT << std::endl;
	std::cout << std::left << std::setw(10) << "Index" << std::setw(10) << "Value" << std::endl;
	std::cout << std::string(20, '-') << std::endl;
	iter(listTest, printIndexAndValue<int>);

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
	// vectorTest();
	listTest();
	
	return 0;
}
