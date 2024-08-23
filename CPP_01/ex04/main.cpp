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
	std::string lineFile;
	std::string originalString;
	std::string concaString;

	validateArgs(argc, argv);

	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	filename = fileNameWithoutExtension(filename);
	originalString = readFileContent(argv);
	concaString = replaceString(originalString, s1, s2);

	std::ofstream outFile(filename.c_str(), std::ofstream::out);
	
	outFile << concaString;

	outFile.close();
	return 0;
}