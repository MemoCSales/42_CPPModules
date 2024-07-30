#include "phonebook.hpp"

void	Phonebook::initOldestIndex() {
	oldestIndex = 0;
}

void	Phonebook::addNewContact() {
	initOldestIndex();
	Contact	newContact;

	if (oldestIndex != 7) {
		newContact = contacts[oldestIndex];
		oldestIndex++;
	}
	else {
		initOldestIndex();
	}
}
