# include "contact.hpp"


Contact::Contact()
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
}

Contact::~Contact()
{
	std::cout	<< "Everything Deleted"
				<< std::endl;
}


void	Contact::setFirstName(const std::string& str)
{
	_firstName = str;
}
void	Contact::setLastName(const std::string& str)
{
	_lastName = str;

}
void	Contact::setNickName(const std::string& str)
{
	_nickName = str;

}
void	Contact::setPhoneNumber(const std::string& str)
{
	_phoneNumber = str;

}
void	Contact::setDarkestSecret(const std::string& str)
{
	_darkestSecret = str;
}
std::string		Contact::getFirstName(void)const
{
	return(_firstName);
}


std::string		Contact::getLastName(void)const
{
	return(_lastName);
}

std::string		Contact::getNickName(void)const
{
	return(_nickName);
}

std::string		Contact::getPhoneNumber(void)const
{
	return(_phoneNumber);
}

std::string		Contact::getDarkestSecret(void)const
{
	return(_darkestSecret);
}