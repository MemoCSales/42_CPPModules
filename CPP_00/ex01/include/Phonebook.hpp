#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define DEFAULT	"\033[0m"

# define DEBUG		0

class Phonebook
{
private:
	Contact contacts[8];
	int		oldestIndex;
public:
	Phonebook();
	void		addNewContact(Contact &newContact);
	void		displayContacts() const;
	void		printingPhonebookHeader() const;
	void		displayContactInfo(int &contactIndex) const;
	std::string	truncateAndFormat(const std::string &str, std::size_t width) const;
	//Getters
	int			getIndex() const;
};

#endif