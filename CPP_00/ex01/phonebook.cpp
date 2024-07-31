#include "phonebook.hpp"

Phonebook::Phonebook() {
	oldestIndex = 0;
}

void	Phonebook::addNewContact(Contact newContact) {
	// initOldestIndex();
	// Contact	newContact;
	// Phonebook();

	if (oldestIndex != 7) {
		contacts[oldestIndex] = newContact;
		oldestIndex++;
	}
	// else {
	// 	Phonebook();
	// }
}

void	Phonebook::displayContacts() const {
	std::cout << BLUE << "THIS IS YOUR PHONEBOOK SO FAR:" << DEFAULT << std::endl;
	std::cout << std::setw(10) << std::right << "Index"
				<< "|" << std::setw(10) << std::right << "First Name"
				<< "|" << std::setw(10) << std::right << "Last Name"
				<< "|" << std::setw(10) << std::right << "Nick Name" << std::endl;
	for (int i = 0; i < 8; ++i) {
		if (contacts[i].getFirstName().empty()) {
			std::cout << std::setw(10) << std::right << i
			<< "|" << std::setw(10) << std::right << contacts[i].getFirstName()
			<< "|" << std::setw(10) << std::right << contacts[i].getLastName()
			<< "|" << std::setw(10) << std::right << contacts[i].getNickName() << std::endl;
		}

	}
}
