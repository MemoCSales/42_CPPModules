#include "Phonebook.hpp"
#include "Contact.hpp"

int main() {
	Phonebook	myPhoneBook;
	std::string option;

	while (1) {
		std::cout << YELLOW << "Choose an option (ADD, SEARCH or EXIT):" << DEFAULT << std::endl;
		std::cin >> option;
		if (option == "ADD")
		{
			Contact 	newContact;
			
			newContact.setContactInformation(newContact);

			if (DEBUG)
				std::cout << "Adding new contact at index: " << myPhoneBook.getIndex() << std::endl;
			myPhoneBook.addNewContact(newContact);
			if (DEBUG)
				std::cout << "Contact added: " << newContact.getFirstName() << " " << newContact.getLastName() << std::endl;
		}
		else if (option == "SEARCH")
		{
			myPhoneBook.displayContacts();
		}
		else if (option == "EXIT") {
			std::cout << RED << "Are you sure you want to exit? Your contacts will be erased forever...☠️" << DEFAULT << std::endl;
			char	flag;
			std::cout << YELLOW << "Press (Y) / Yes or (N) / No: " << DEFAULT;
			std::cin >> flag;
			if (flag == 'Y') {
				std::cout << WHITE << "Bye bye *Hangs Up*" << DEFAULT << std::endl;
				break;
			}
			else
				continue;
		}
		else
			std::cout << RED << "Error: Not the right option. Try again." << DEFAULT << std::endl;
	}
	return 0;
}
