#include <iostream>
#include <string>

#define RED			"\033[1;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"
#define BLUE		"\033[1;34m"
#define MAGENTA		"\033[1;35m"
#define CYAN		"\033[1;36m"
#define WHITE		"\033[1;37m"
#define DEFAULT		"\033[0m"

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << GREEN << "Memory address test: " << DEFAULT << std::endl;
	std::cout << "Memory address of the string:     " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address help by stringREF: " << &stringREF << std::endl;

	std::cout << GREEN << "Values testing: " << DEFAULT << std::endl;
	std::cout << "The value of the string: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}
