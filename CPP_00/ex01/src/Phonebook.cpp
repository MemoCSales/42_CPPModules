#include "Phonebook.hpp"

Phonebook::Phonebook() {
	oldestIndex = 0;
}

int		Phonebook::getIndex() const {
	return oldestIndex;
}

void	Phonebook::addNewContact(Contact &newContact) {
	if (DEBUG)
		std::cout << "Adding contact at index: " << oldestIndex << std::endl;

	contacts[oldestIndex] = newContact;
	oldestIndex = (oldestIndex + 1) % 8;

	if (DEBUG)
		std::cout << "New oldest index is: " << oldestIndex << std::endl;
}

std::string	Phonebook::truncateAndFormat(const std::string &str, std::size_t width) const {
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	else
		return str;
}

void	Phonebook::printingPhonebookHeader() const {
	std::cout << BLUE << "📒 THIS IS YOUR PHONEBOOK: 📒" << DEFAULT << std::endl;
	std::cout << std::setw(10) << std::right << "Index"
				<< "|" << std::setw(10) << std::right << "First Name"
				<< "|" << std::setw(10) << std::right << "Last Name"
				<< "|" << std::setw(10) << std::right << "Nick Name" << std::endl;
}

void	Phonebook::displayContacts() const {
	if (contacts[0].getFirstName().empty())
		std::cout << RED << "No contacts have been added so far. Try ADD a new contact first." << DEFAULT << std::endl;
	else {
		printingPhonebookHeader();
		for (int i = 0; i < 8; i++) {
			std::cout << std::setw(10) << std::right << i
			<< "|" << std::setw(10) << std::right << truncateAndFormat(contacts[i].getFirstName(), 10)
			<< "|" << std::setw(10) << std::right << truncateAndFormat(contacts[i].getLastName(), 10)
			<< "|" << std::setw(10) << std::right << truncateAndFormat(contacts[i].getNickName(), 10) << std::endl;
		}
		int	index;
		std::cout << WHITE << "📣 Enter the index from the contact you want more information: " << DEFAULT;
		std::cin >> index;
		displayContactInfo(index);
	}
}

void	Phonebook::displayContactInfo(int &contactIndex) const {
	if (contactIndex >= 0 && contactIndex <= 7) {
		std::cout << "👤 Contact number["<< contactIndex <<"]" << std::endl;
		std::cout << "◽️ First Name: " << contacts[contactIndex].getFirstName() << std::endl;
		std::cout << "◽️ Last Name: "<< contacts[contactIndex].getLastName() << std::endl;
		std::cout << "◽️ Nick Name: "<< contacts[contactIndex].getNickName() << std::endl;
		std::cout <<"◽️ Phone number: "<< contacts[contactIndex].getPhoneNumber() << std::endl;
		std::cout << "◽️ Darkest Secret: "<< contacts[contactIndex].getDarkestName() << std::endl;
	}
	else {
		std::cout << RED << "Invalid Index" << DEFAULT << std::endl;
	}
}
