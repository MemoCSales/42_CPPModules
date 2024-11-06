# include "RPN.hpp"

int main(int argc, char** argv) {
	// (void)argc;
	// (void)argv;

	if (argc != 2) {
		std::cerr << ERROR_MESSAGE << std::endl;
		return 1;
	}
	RPN rpn;
	if (!rpn.parsing(argv[1])) {
		return 1;
	}

	// if (!rpn.solving(argv[1])) {
	// 	return 1;
	// }

	// std::cout << "main function yay" << std::endl;

	return 0;
}
