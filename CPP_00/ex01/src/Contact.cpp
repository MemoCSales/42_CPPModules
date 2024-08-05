#include "Contact.hpp"
#include "Phonebook.hpp"

void	Contact::setContactInformation(Contact &newContact) {
	std::string input;
	long	number;

	while (true) {
		std::cout << GREEN << "Enter First Name: " << DEFAULT;
		std::getline(std::cin, input);
		if (input.empty()) {
			std::cout << RED << "No fields should be left empty. Please try again." DEFAULT << std::endl;
			continue;
		} else {
			newContact.setFirstName(input);
			break;
		}
	}
	while(true) {
		std::cout << GREEN << "Enter Last Name: " << DEFAULT;
		std::getline(std::cin, input);
		if (input.empty()) {
			std::cout << RED << "No fields should be left empty. Please try again." DEFAULT << std::endl;
		} else {
			newContact.setLastName(input);
			break;
		}
	}
	while (true) {
		std::cout << GREEN << "Enter Nick Name: " << DEFAULT;
		std::getline(std::cin, input);
		if (input.empty()) {
			std::cout << RED << "No fields should be left empty. Please try again." DEFAULT << std::endl;
		} else {
			newContact.setNickName(input);
			break;
		}
	}

	number = getValidPhoneNumber(newContact);
	newContact.setPhoneNumber(number);
	
	while (true) {
		std::cout << GREEN << "Enter your Darkest Secret: " << DEFAULT;
		std::getline(std::cin, input);
		if (input.empty()) {
			std::cout << RED << "No fields should be left empty. Please try again." DEFAULT << std::endl;
		} else {
			newContact.setDarkestSecret(input);
			break;
		}
	}
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


bool	Contact::phoneNumberValidation(std::string &phoneNumber) {
	if (phoneNumber.length() == 0) {
		std::cout << RED << "No fields should be left empty. Please try again." DEFAULT << std::endl;
		return false;
	}
	for (size_t i = 0; i < phoneNumber.length(); i++) {
		if (!std::isdigit(phoneNumber[i]) || phoneNumber[i] == '\0') {
			std::cerr << RED << "Enter a valid number (No signs, no spaces. Just numbers). Try again." << DEFAULT << std::endl;
			return false;
		}
	}
	return true;
}

long	Contact::stringToLong(const std::string &str) {
	std::stringstream	ss(str);
	long				result;

	ss >> result;
	return result;
}

long	Contact::getValidPhoneNumber(Contact &newContact) {
	std::string	input;
	bool isValid = false;
	long	number;

	while (!isValid) {
		std::cout << GREEN << "Enter your phone number: " << DEFAULT;
		std::getline(std::cin, input);

		isValid = true;
		if (!newContact.phoneNumberValidation(input)) {
			isValid = false;
			continue ;
		}
	}
	if (isValid) {
		number = stringToLong(input);
	}
	return number;
}

bool	Contact::checkEmptyInput() {
	std::string input;
	
	if (!getFirstName().empty())
		return true;
	else
		return false;
}