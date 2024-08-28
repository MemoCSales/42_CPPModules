#include "Harl.hpp"

typedef void(Harl::*myPointerToFunction) (void);

Harl::Harl()
{
	if (DEBUG)
		std::cout << "Default constructor called" << std::endl;
}

Harl::~Harl()
{
	if (DEBUG)
		std::cout << "Destructor called" << std::endl;
}

//Private methods
void	Harl::debug(void) {
	std::cout << YELLOW << "DEBUG: " << DEFAULT << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << WHITE << "INFO: " << DEFAULT << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << CYAN << "WARNING: " << DEFAULT << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << RED << "ERROR: " << DEFAULT << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Level Harl::resolveLevel(const std::string& level) {
	if (level == "DEBUG") return DEBUG1;
	if (level == "INFO") return INFO;
	if (level == "WARNING") return WARNING;
	if (level == "ERROR") return ERROR;
	return INVALID;
}

//Public method
void	Harl::complain(std::string level) {
	Level lvl = resolveLevel(level);
	//FunctionPointer is an array of pointers to member functions of the Harl class
	myPointerToFunction functionPointer[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	switch (lvl)
	{
		case DEBUG1:
			//calls the appropriate member function on the current instance of Harl
			(this->*functionPointer[lvl]) ();
			break;
		case INFO:
			(this->*functionPointer[lvl]) ();
			break;
		case WARNING:
			(this->*functionPointer[lvl]) ();
			break;
		case ERROR:
			(this->*functionPointer[lvl]) ();
			break;
		
		default:
			std::cout << GREEN << "INVALID: " << DEFAULT << "I'm impressed about this service. Thank you" << std::endl;
			break;
	}
}
