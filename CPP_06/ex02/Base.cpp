#include "Base.hpp"

// ----Destructor
Base::~Base() {
	if (DEBUG) {
		std::cout << "Base destructor called" << std::endl;
	}
}
