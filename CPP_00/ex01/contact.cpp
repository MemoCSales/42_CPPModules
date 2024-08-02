#include "contact.hpp"

void	Contact::setContactInformation(Contact &newContact) {
	std::string input;
	long	number;

	std::cout << "Enter First Name: ";
	std::cin >> std::ws;
	std::getline(std::cin, input);
	newContact.setFirstName(input);

	std::cout << "Enter Last Name: ";
	std::getline(std::cin, input);
	newContact.setLastName(input);

	std::cout << "Enter Nick Name: ";
	std::getline(std::cin, input);
	newContact.setNickName(input);

	std::cout << "Enter your phone number: ";
	std::cin >> number;
	newContact.setPhoneNumber(number);
	std::cin.ignore();
	
	std::cout << "Enter your Darkest Secret: ";
	std::getline(std::cin, input);
	newContact.setDarkestSecret(input);
}

//Setters
void	Contact::setFirstName(const std::string &fName) {
	firstName = fName;
}
void	Contact::setLastName(const std::string &lName) {
	lastName = lName;
}
void	Contact::setNickName(const std::string &nName) {
	nickName = nName;
}
void	Contact::setDarkestSecret(const std::string &dSecret) {
	darkestSecret = dSecret;
}
void	Contact::setPhoneNumber(long &pNumber) {
	phoneNumber = pNumber;
}

//Getters
std::string Contact::getFirstName() const {
	return firstName;
}
std::string Contact::getLastName() const {
	return lastName;
}
std::string Contact::getNickName() const {
	return nickName;
}
std::string Contact::getDarkestName() const {
	return darkestSecret;
}
long	Contact::getPhoneNumber() const {
	return phoneNumber;
}
