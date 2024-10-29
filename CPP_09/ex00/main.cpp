# include "BitcoinExchange.hpp"

int main (int argc, char** argv) {

	(void)argv;
	int returnValue = 0;
	validateArgs(argc);
	returnValue = fileManagement(argv);

	return returnValue;
}