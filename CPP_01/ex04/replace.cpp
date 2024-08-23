#include "Sed.hpp"

void	validateArgs(int argc, char **argv) {
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (argc != 4) {
		std::cerr << RED << "\tError: " << DEFAULT << WHITE << " ./program_name filename string1 string2" << DEFAULT << std::endl;
		exit(EXIT_FAILURE);
	}

	if (s1.empty() || s2.empty()) {
		std::cout << "Error: Empty string found. Please try again with valid string input." << std::endl;
		exit(EXIT_FAILURE);
	}
}

//Remove the extension from the file, by searching from the end of the string
//rfind returns the index of the dot within the stirng.
std::string fileNameWithoutExtension(std::string &filename) {
	std::string fileExtension = ".replace";
	size_t	lastDot = filename.rfind('.');
	//npos = "no position"
	if (lastDot != std::string::npos) {
		filename = filename.substr(0, lastDot);
	}
	return filename.append(fileExtension);
}

std::string readFileContent(char **argv) {
	std::ifstream inFile(argv[1], std::ifstream::in);
	std::string originalString;

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
	inFile.close();
	return originalString;
}

std::string replaceString(std::string &originalString, std::string &s1, std::string &s2) {
	std::string concaString;
	std::size_t	initPos = originalString.find(s1);
	if (initPos == std::string::npos)
		std::cout << "No string in the file matches with string1. Try again..." << std::endl;

	size_t	i = 0;
	while (originalString[i]) {
		initPos = originalString.find(s1, i);
		if (i == initPos) {
			concaString += s2;
			i += s1.length();
		}
		else {
			concaString += originalString[i];
			i++;
		}
	}
	return concaString;
}