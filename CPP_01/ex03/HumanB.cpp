#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : name(_name) {
	if (DEBUG)
		std::cout << "Default constructor called in HumanB class" << std::endl;
}

HumanB::~HumanB()
{
	if (DEBUG)
		std::cout << "Default deconstructor called in HumanB class" << std::endl;
}