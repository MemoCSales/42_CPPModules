#include "ScalarConverter.hpp"

void testConversion(const std::string& literal) {
	std::cout << "Testing conversion for: " << literal << std::endl;
	ScalarConverter::convert(literal);
	std::cout << std::endl;
}

int	main(int argc, char **argv) {
	(void)argv;
	if (argc < 2)
	{
		std::cerr << "Literal missing!\n";
		std::cerr << "Usage: ./cast <literal>..." << std::endl;
		return -1;
	}
	std::string arg(argv[1]);
	ScalarConverter::convert(arg);
	// testConversion("a");
	// testConversion("42");
	// testConversion("-42");
	// testConversion("+42");
	// testConversion("nan");
	// testConversion("+inf");
	// testConversion("-inf");
	// testConversion("inf");
	
	return 0;
}
