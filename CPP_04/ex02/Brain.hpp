#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include "Animal.hpp"

class Brain
{
protected:
	std::string ideas[100];
public:
	Brain(void);
	Brain(const Brain& other);
	Brain &operator=(const Brain &other);
	~Brain();
	// Setters
	void	setIdea(int index, const std::string &idea);
	// Getters
	std::string getIdea(int index) const;
};


#endif
