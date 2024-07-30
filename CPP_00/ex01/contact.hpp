#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string darkestSecret;
	int         phoneNumber;
public:
	//Setters
	void	setFirstName(const std::string &fName);
	void	setLastName(const std::string &lName);
	void	setNickName(const std::string &nName);
	void	setDarkestSecret(const std::string &dSecret);
	void	setPhoneNumber(int &pNumber);
	//Getters
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getDarkestName() const;
	int	getPhoneNumber() const;
};

#endif