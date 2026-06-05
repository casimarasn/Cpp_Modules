#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		Contact();
		~Contact();
		void	setFirstName(const std::string& str);
		void	setLastName(const std::string& str);
		void	setNickName(const std::string& str);
		void	setPhoneNumber(const std::string& str);
		void	setDarkestSecret(const std::string& str);

		std::string	getFirstName(void)const;
		std::string	getLastName(void)const;
		std::string	getNickName(void)const;
		std::string	getPhoneNumber(void)const;
		std::string	getDarkestSecret(void)const;

		void	printRow(int index)const;
		void	printDetails(void)const;

};

#endif
