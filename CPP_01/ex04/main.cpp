#include "Sed.hpp"

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
	std::string originalString;

	if (argc != 4) {
		std::cerr << RED << "\tError: " << DEFAULT << WHITE << " ./program_name filename string1 string2" << DEFAULT << std::endl;
		exit(EXIT_FAILURE);
	}
	
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	std::size_t lenStr1 = s1.length();
	std::size_t lenStr2 = s2.length();
	if (lenStr1 <= 0 || lenStr2 <= 0) {
		std::cout << "Error: Empty string found. Please try again with valid string input." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	//Remove the extension from the file, by searching from the end of the string
	//rfind returns the index of the dot within the stirng.
	size_t	lastDot = filename.rfind('.');
	//npos = "no position"
	if (lastDot != std::string::npos) {
		filename = filename.substr(0, lastDot);
	}
	
	std::ifstream inFile(argv[1], std::ifstream::in);

	filename.append(fileExtension);

	if (inFile.is_open()) {
		char	c;
		while (inFile.get(c)) {
			originalString += c;
		}
	}
	else {
		std::cerr << "Error opening file. Check filename." << std::endl;
		exit(EXIT_FAILURE);
	}

	std::size_t	initPos = originalString.find(s1);
	if (initPos == std::string::npos)
		std::cout << "No string in the file matches with string1. Try again..." << std::endl;

	size_t	i = 0;
	std::string concaString;
	while (originalString[i]) {
		initPos = originalString.find(s1, i);
		if (i == initPos) {
			concaString += s2;
			i += lenStr1;
		}
		else {
			concaString += originalString[i];
			i++;
		}
	}
	std::ofstream outFile(filename.c_str(), std::ofstream::out);
	
	outFile << concaString;

	outFile.close();
	inFile.close();
	return 0;
}