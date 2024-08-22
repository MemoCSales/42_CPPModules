#include "Sed.hpp"

using namespace std;
/*
create a program that takes 3 parameters in the following order:
	filename
	s1
	s2
It will open the file <filename> and copies its content into a new file <filename>.replace --> It will replace every occurence of s1 with s2
*/
int main(int argc, char **argv) {
	
	std::string	filename, outFileName, s1, s2;
	std::string fileExtension = ".replace";
	std::string lineFile;
	std::string tempString;

	if (argc != 4)
		std::cerr << RED << "\tError: " << DEFAULT << WHITE << " ./program_name filename string1 string2" << DEFAULT << std::endl;
	
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	//Remove the extension from the file, by searching from the end of the string
	//rfind returns the index of the dot within the stirng.
	size_t	lastDot = filename.rfind('.');
	//npos = "no position"
	if (lastDot != std::string::npos) {
		filename = filename.substr(0, lastDot);
	}

	// std::cout << "Filename: " <<  filename << std::endl;
	// std::cout << "String1: " <<  s1 << std::endl;
	// std::cout << "String2: " <<  s2 << std::endl;
	
	std::ifstream inFile(argv[1], std::ifstream::in);

	// if (!inFile.is_open()) {
	// 	// std::cout << "File: " << filename << " opened successfully." << std::endl;
	// 	std::getline(inFile, lineFile);
	// 	// std::cout << lineFile << std::endl;
	// }
	// else

	filename.append(fileExtension);

	if (inFile.is_open()) {
		char	c;
		while (inFile.get(c)) {
			tempString += c;
		}
	}
	else {
		std::cerr << "Error opening file. Check filename." << std::endl;
	}
	std::cout << tempString << std::endl;


	std::size_t	found = tempString.find(s1);
	if (found != std::string::npos)
		std::cout << "Ocurrence of string: " << s1 << " found at position: " << found << std::endl;
	else
		std::cout << "String: " << s1 << " not found." << std::endl;

	
	std::ofstream outFile(filename.c_str(), std::ofstream::out);
	outFile.close();
	inFile.close();
	return 0;
}