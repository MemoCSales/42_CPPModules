# include "RPN.hpp"

int main(int argc, char** argv) {

	if (argsValidation(argc, argv)) {
		RPN rpn;
		if (!rpn.parsing(argv[1])) {
			return 1;
		}
	}

	return 0;
}
