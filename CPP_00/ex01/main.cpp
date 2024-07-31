#include "phonebook.hpp"
#include "contact.hpp"

int main() {
	Phonebook	myPhoneBook;
	Contact 	newContact;
	std::string input, option;
	int			phoneNumber = 0;
	
	// myPhoneBook.initOldestIndex();

	while (1) {
		std::cout << YELLOW << "Choose an option:" << DEFAULT << std::endl;
		std::cin >> option;
		if (option == "ADD")
		{
			std::cout << "Enter First Name: ";
			std::cin >> input;
			newContact.setFirstName(input);
			std::cout << "Enter Last Name: ";
			std::cin >> input;
			newContact.setLastName(input);
			std::cout << "Enter Nick Name: ";
			std::cin >> input;
			newContact.setNickName(input);
			std::cout << "Enter your phone number: ";
			std::cin >> phoneNumber;
			newContact.setPhoneNumber(phoneNumber);
			std::cin.ignore();
			std::cout << "Enter your Darkest Secret: ";
			std::getline(std::cin, input);
			newContact.setDarkestSecret(input);
			// std::cout << "Your First Name is: " << newContact.getFirstName() << std::endl;
			// std::cout << "Your Last Name is: " << newContact.getLastName() << std::endl;
			// std::cout << "Your Nick Name is: " << newContact.getNickName() << std::endl;
			// std::cout << "Your Phone Number is: " << newContact.getPhoneNumber() << std::endl;
			// std::cout << "Your Darkest Secret is: " << newContact.getDarkestName() << std::endl;
			myPhoneBook.addNewContact(newContact);
		}
		else if (option == "SEARCH")
		{
			myPhoneBook.displayContacts();
		}
		else if (option == "EXIT") {
			std::cout << WHITE << "Bye bye" << DEFAULT << std::endl;
			break;
		}
		else {
			std::cout << RED << "Error: Not the right option. Try again." << DEFAULT << std::endl;
		}
	}
	return 0;
}

// int main(int argc, char **argv) {
// 	std::string firstName, lastName, nickName, darkestSecret;
// 	int phoneNumber;
// 	(void)argc;
// 	(void)argv;

// 	std::cout << "Enter First Name: ";
// 	std::cin >> firstName;
// 	std::cout << "Enter Last Name: ";
// 	std::cin >> lastName;
// 	std::cout << "Enter your Nick Name: ";
// 	std::cin >> nickName;
// 	std::cout << "Enter your Phone Number: ";
// 	std::cin >> phoneNumber;
// 	std::cin.ignore();
// 	std::cout << "Enter your Darkest Secret: ";
// 	std::getline(std::cin, darkestSecret);
// 	std::cout << "Your First Name is: " << firstName << std::endl;
// 	std::cout << "Your Last Name is: " << lastName << std::endl;
// 	std::cout << "Your Nick Name is: " << nickName << std::endl;
// 	std::cout << "Your Phone Number is: " << phoneNumber << std::endl;
// 	std::cout << "Your Darkest Secret is: " << darkestSecret << std::endl;
// }