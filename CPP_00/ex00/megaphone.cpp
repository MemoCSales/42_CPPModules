#include <string>
#include <iostream>
#include <cctype>

class Megaphone
{
	private:
		std::string originalMessage;
		std::string transformedMessage;
	public:
		Megaphone(int argc, char **argv);	//Construct with parameter
		void transformMessage();
		void printMessage();
};

//Constructor definition outside the class
Megaphone::Megaphone(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		if (i > 1) {
			originalMessage += " ";
		}
		originalMessage += argv[i];
	}
}

//Constructor definition outside the class
void Megaphone::transformMessage() {
	transformedMessage = originalMessage;
	for (std::size_t i = 0; i < originalMessage.size(); i++) {
		transformedMessage[i] = std::toupper(originalMessage[i]);
	}
}

//Constructor definition outside the class
void Megaphone::printMessage() {
	std::cout << transformedMessage << std::endl;
}

int	main(int argc, char **argv) {
	if (argc > 1) {
		Megaphone megaphone(argc, argv);
		megaphone.transformMessage();
		megaphone.printMessage();
	}
	else {
		std::cout << "* LOUD and UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return (0);
}
