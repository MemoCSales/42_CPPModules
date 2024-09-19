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
	virtual ~Animal();
	// Methods
	virtual void	makeSound() const;
	// Setters
	void	setType(std::string type);
	// Getters
	virtual std::string getType() const;
};

#endif