#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

# define DEBUG 1

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENT		"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE	 	"\033[1;37m"
# define DEFAULT	"\033[0m"

class Animal
{
protected:
	std::string	type;
public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	~Animal();
	// Methods
	
};

Animal::Animal(void) {
	if (DEBUG)
		std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string _type) : type(_type) 
{
	if (DEBUG)
		std::cout << "Animal parameter constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	if (DEBUG)
		std::cout << "Animal copy constructor called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
}

Animal &Animal::operator=(const Animal &other) {
	if (DEBUG)
		std::cout << "Animal Operator Overload called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}


Animal::~Animal()
{
	if (DEBUG)
		std::cout << "Animal destructor called" << std::endl;
}



#endif