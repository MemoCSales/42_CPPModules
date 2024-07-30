// #include "phonebook.hpp"
#include "contact.hpp"

int main() {
    Contact myContact;

    myContact.setFirstName("Manuel");
    std::cout <<myContact.getFirstName();
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