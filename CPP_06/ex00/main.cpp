#include "ScalarConverter.hpp"

void testConversion(const std::string& literal) {
	std::cout << "Testing conversion for: " << literal << std::endl;
	ScalarConverter::convert(literal);
	std::cout << std::endl;
}

int	main(int argc, char **argv) {
	// (void)argv;
	// (void)argc;
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
	// testConversion("2147483647"); // Max value
	// testConversion("2147483648"); // Invalid max int value
	// testConversion("-1.7976931348623157E+308"); // Lowest double value
	// testConversion("1.7976931348623157E+308");
	// testConversion("3.4028235E+38"); // Max float value
	// testConversion("1.17549435E-38"); // Min float value
	
	return 0;
}
