#include "contact.hpp"

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
void	Contact::setPhoneNumber(int &pNumber) {
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
int	Contact::getPhoneNumber() const {
	return phoneNumber;
}