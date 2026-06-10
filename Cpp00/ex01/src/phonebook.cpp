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

void	PhoneBook::addContact()
{
	std::string	first;
	std::string	last;
	std::string	nick;
	std::string	phone;
	std::string	secret;

	do {
		std::cout	<< "Cuál es tu Nombre?" << std::endl;
		std::getline(std::cin, first);
		if (first.empty())
			std::cout	<< "Oye, tengo que saber cómo llamarte" << std::endl;
	}while (first.empty());

	do {
		std::cout	<< "Y tu Appelido?" << std::endl;
		std::getline(std::cin, last);
		if (last.empty())
			std::cout	<< "esa casta siempre presente,venga! " << std::endl;
	}while (last.empty());
	do {
		std::cout	<< "Por qué Mote te conocen?" << std::endl;
		std::getline(std::cin, nick);
		if (!nick.empty())
			std::cout	<< "el mote es tu marca de identidad, dime!" << std::endl;
	}while (nick.empty());
	do {
		std::cout	<< "dime tu telefono" << std::endl;
		std::getline(std::cin, phone);
		if (phone.empty())
			std::cout	<< "venga, ahora un telefono válido" << std::endl;
	}while (phone.empty());
	do {
		std::cout << "Shhh!Cuentame un secreto ozzcuro" << std::endl;
		std::getline(std::cin, secret);
		if (secret.empty())
		std::cout	<< "Venga soy una tumba!ese chisme aqui!" << std::endl;
	}while (secret.empty());

	_contacts[i].setFirstName(first);
	_contacts[i].setLastName(last);
	_contacts[i].setNickName(nick);
	_contacts[i].setPhoneNumber(phone);
	_contacts[i].setDarkestSecret(secret);
}