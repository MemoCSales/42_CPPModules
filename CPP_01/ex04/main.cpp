#include <string>
#include <iostream>
#include <fstream>

# define DEBUG	0

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE	 	"\033[1;37m"
# define DEFAULT	"\033[0m"

/*
create a program that takes 3 parameters in the following order:
	filename
	s1
	s2
It will open the file <filename> and copies its content into a new file <filename>.replace --> It will replace every occurence of s1 with s2
*/
int main(int argc, char **argv) {
	
	std::string	filename, s1, s2;

	if (argc != 4)
		std::cerr << RED << "\tError: " << DEFAULT << WHITE << " ./program_name filename string1 string2" << DEFAULT << std::endl;
	
	filename = argv[1];
	s1 = argv[3];
	s2 = argv[2];

	std::cout << "Filename: " <<  filename << std::endl;
	std::cout << "String1: " <<  s1 << std::endl;
	std::cout << "String2: " <<  s2 << std::endl;
	
	std::ifstream ifs;
	ifs.open(argv[1], std::ifstream::in);
	if (ifs.is_open())
		std::cout << "File: " << filename << " opened successfully." << std::endl;
	else
		std::cerr << "Error opening file." << std::endl;

	ifs.close();

	return 0;
}