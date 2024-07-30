#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "contact.hpp"

class Phonebook
{
private:
	Contact contacts[8];
	int		oldestIndex;
public:
	void	initOldestIndex();
	void	addNewContact();
	//
};

#endif