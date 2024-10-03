#include "ScalarConverter.hpp"

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

	
	return 0;
}
