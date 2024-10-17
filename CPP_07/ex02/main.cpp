# include <iostream>
# include "Array.hpp"

# define MAX_VAL 750

void testArrayBounds() {
	Array<int> numbers(MAX_VAL);

	try
	{
		numbers[-1] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}    
}

void testArrayCopy() {
	Array<int> numbers(MAX_VAL);
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = i;
	}

	Array<int> copy = numbers;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (copy[i] != numbers[i])
		{
			std::cout << "Copy constructor failed at index " << i << std::endl;
			return ;
		}
	}
	
	Array<int> assigned;
	assigned = numbers;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (assigned[i] != numbers[i])
		{
			std::cout << "Assignment operator failed at index " << i << std::endl;
			return ;
		}
	}
	
	std::cout << GREEN <<"Copy constructor and assignment operator passed the tests" << DEFAULT<< std::endl;
}

void testArraySize() {
	Array<int> numbers(MAX_VAL);

	if (numbers.size() != MAX_VAL)
	{
		std::cerr << RED << "Size method failed." << DEFAULT << std::endl;
	} else {
		std::cerr << GREEN << "Size method passed." << DEFAULT << std::endl;
	}
}

void testEmptyArray() {
	Array<int> empty;

	if (empty.size() != 0)
	{
		std::cerr << RED << "Size method failed." << DEFAULT << std::endl;
	} else {
		std::cerr << GREEN << "Size method passed." << DEFAULT << " Size: " << empty.size() << std::endl;
	}
	try
	{
		empty[0] = 1;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Empty array is initialized by NULL. Cannot assign any values into it." << DEFAULT << '\n';
	}
	
}

char randomUppercaseLetter() {
	return 'A' + rand() % 26;
}


int main() {
	std::cout << CYAN << "Testing Array Bounds:" << DEFAULT << std::endl;
	testArrayBounds();
	std::cout << "\n";
	std::cout << CYAN << "Testing Array Copy:" << DEFAULT << std::endl;
	testArrayCopy();
	std::cout << "\n";
	std::cout << CYAN << "Testing Array Size:" << DEFAULT << std::endl;
	testArraySize();
	std::cout << "\n";
	std::cout << CYAN << "Testing Empty Array: " << DEFAULT << std::endl;
	testEmptyArray();

	std::cout << "Other types of array: " << std::endl;
	Array<char> arrayStr(MAX_VAL);

	srand(static_cast<unsigned int>(time(0)));


	for (size_t i = 0; i < arrayStr.size(); i++)
	{
		std::cout << randomUppercaseLetter();
	}
	std::cout << std::endl;
	
	return 0;
}