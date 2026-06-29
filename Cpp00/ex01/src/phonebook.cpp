#include "phonebook.hpp"

PhoneBook::PhoneBook() : _index(0), _totalContacts(0) {
}

PhoneBook::~PhoneBook()
{
	std::cout	<< "Everything Deleted"
				<< std::endl;
}

void	PhoneBook::printTable()const
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

void	PhoneBook::printDetails(int index)const
{
	std::cout	<< "Name: "
				<< _contacts[index].getFirstName()
				<< std::endl;

	std::cout	<< "Surname: "
				<< _contacts[index].getLastName()
				<< std::endl;

	std::cout	<< "Nickname: : "
				<< _contacts[index].getNickName()
				<< std::endl;

	std::cout	<< "Phone: "
				<< _contacts[index].getPhoneNumber()
				<< std::endl;
	std::cout	<< "Dark Secret: "
				<< _contacts[index].getDarkestSecret()
				<< std::endl;
}

bool	PhoneBook::isInputEof()
{
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return (true);
	}
	return (false);
	
}

bool PhoneBook::isAscii(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (static_cast<unsigned char>(input[i]) > 127 || static_cast<unsigned char>(input[i]) == '\t')
			return (false);
	}
	return (true);
}

void	PhoneBook::addContact()
{
	std::string	input;

	do {
		std::cout	<< "what is your Name?" << std::endl;
		
		std::getline(std::cin, input);
		if (isInputEof())
			return ;
		if (input.empty() || !isAscii(input))
			std::cout	<< "Hey, I've got to know how I can call you" << std::endl;
	}while (input.empty() || !isAscii(input));
	_contacts[_index].setFirstName(input);
	do {
		std::cout	<< "And your Surname?" << std::endl;
		std::getline(std::cin, input);
		if (isInputEof())
			return ;
		if (input.empty() || !isAscii(input))
			std::cout	<< "The family name always present,come on! " << std::endl;
	}while (input.empty() || !isAscii(input));
	_contacts[_index].setLastName(input);
	do {
		std::cout	<< "What nickname do people know you by?" << std::endl;
		std::getline(std::cin, input);
		if (isInputEof())
			return ;
		if (input.empty() || !isAscii(input))
		std::cout	<< "Your nickname is your mark of identity, tell me!" << std::endl;
	}while (input.empty() || !isAscii(input));
	_contacts[_index].setNickName(input);
	do {
		std::cout	<< "Tell me your phone" << std::endl;
		std::getline(std::cin, input);
		if (isInputEof())
			return ;
		if (input.empty() || !isAscii(input))
			std::cout	<< "come on, now a valid number" << std::endl;
	}while (input.empty() || !isAscii(input));
	_contacts[_index].setPhoneNumber(input);
	do {
		std::cout << "Shhh!Tell me a dark secret" << std::endl;
		std::getline(std::cin, input);
		if (isInputEof())
			return ;
		if (input.empty() || !isAscii(input))
		std::cout	<< "come on! I'm a tomb!that secret here!" << std::endl;
	}while (input.empty() || !isAscii(input));
	_contacts[_index].setDarkestSecret(input);
	_index++;
	if (_index == 8)
		_index = 0;
	if ( _totalContacts < 8)
		_totalContacts++;
}

void	PhoneBook::searchContact()
{
	std::string	input;
	bool	valid = false;

	if (_totalContacts == 0)
	{
		std::cout	<< "There is no contacts still saved. ¡Add a new one!"
					<< std::endl;
		return;
	}
	printTable();
	do {
		std::cout	<< "Choose a contact for more details" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return;
		if (input.empty())
		{
			std::cout << "¿Are you kidding Me?"
						<< std::endl
						<< "> ";
		}
		else if ((input.length() != 1) || !(input[0] >= '0' && input[0] <= '7'))
			std::cout	<< "Sweetie...a valid one, if possible..." << std::endl;
		else
		{
			int	num = input[0] - '0';
			if (num >= _totalContacts)
				std::cout << "It doesn't exist yet, give it time" << std::endl;
			else
			{
				printDetails(num);
				valid = true;
			}
		}
	} while (!valid);
}



