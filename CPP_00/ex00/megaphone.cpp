#include <string>
#include <iostream>

std::string megaphone( std::string message) {
	for (std::size_t i = 0; i < message.size(); i++) {
		message[i] = std::toupper(message[i]);
	}
	return message;
}

int	main(int argc, char **argv) {
	std::string message;
	if (argc > 1) {
		for(int i = 0; i < argc; i++) {
			message = megaphone(argv[i]);
		}
		std::cout << message << std::endl;
	} else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return (0);
}