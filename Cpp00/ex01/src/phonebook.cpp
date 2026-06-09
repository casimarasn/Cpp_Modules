#include "phonebook.hpp"

PhoneBook::PhoneBook() : _index(0), _totalContacts(0) {
}

PhoneBook::~PhoneBook()
{
	std::cout	<< "Everything Deleted"
				<< std::endl;
}

void	PhoneBook::printTable(int index)const
{
	std::cout	<< "| "
				<< std::setw(10) << "Index" << " | "
				<< std::setw(10) << "First Name"<< " | "
				<< std::setw(10) << "Last Name"<< " | "
				<< std::setw(10) << "Nickname"<< " |"
				<< std::endl;
	for (int i = 0; i < _totalContacts; i++)
	{
		std::string	first = _contacts[i].getFirstName();
		std::string	last = _contacts[i].getLastName();
		std::string	nick = _contacts[i].getNickName();

		std::cout	<< "| "
					<< std::setw(10) << i << " | ";
		if (first.length() > 10)
			std::cout << std::setw(10) << first.substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << first;
		std::cout << " | ";
		if (last.length() > 10)
			std::cout << std::setw(10) << last.substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << last;
		std::cout << " | ";
		if (nick.length() > 10)
			std::cout << std::setw(10) << nick.substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << nick;
		std::cout << " |";
		std::cout << std::endl;
	}
				
				
				
}