#include "Harl.hpp"

typedef void(Harl::*myPointerToMethod) (std::string);

int	main(void) {
	
	std::string	level = "DEBUG";
	Harl	harlObj;
	// myPointerToMethod ptr = &Harl::complain;

	// //Initialize Harl
	// (harlObj.*ptr) (level);
	harlObj.complain(level);
	return 0;
}