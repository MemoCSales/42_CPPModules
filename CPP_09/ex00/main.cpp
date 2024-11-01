# include "BitcoinExchange.hpp"

int main (int argc, char** argv) {

	int returnValue = 0;
	validateArgs(argc);
	BitcoinExchange bit;
	if(!(bit.dataBaseManagement())) return 1;
	
	returnValue = bit.fileManagement(argv);

	return returnValue;
}
