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
	std::cout	<< "Nombre: "
				<< _contacts[index].getFirstName()
				<< std::endl;

	std::cout	<< "Apellido: "
				<< _contacts[index].getLastName()
				<< std::endl;

	std::cout	<< "Mote: : "
				<< _contacts[index].getNickName()
				<< std::endl;

	std::cout	<< "Teléfono: "
				<< _contacts[index].getPhoneNumber()
				<< std::endl;
	std::cout	<< "Oscuro Secreto: "
				<< _contacts[index].getDarkestSecret()
				<< std::endl;
}


void	PhoneBook::addContact()
{
	std::string	input;

	do {
		std::cout	<< "Cuál es tu Nombre?" << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout	<< "Oye, tengo que saber cómo llamarte" << std::endl;
	}while (input.empty());
	_contacts[_index].setFirstName(input);
	do {
		std::cout	<< "Y tu Appelido?" << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout	<< "esa casta siempre presente,venga! " << std::endl;
	}while (input.empty());
	_contacts[_index].setLastName(input);
	do {
		std::cout	<< "Por qué Mote te conocen?" << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
		std::cout	<< "el mote es tu marca de identidad, dime!" << std::endl;
	}while (input.empty());
	_contacts[_index].setNickName(input);
	do {
		std::cout	<< "dime tu telefono" << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout	<< "venga, ahora un telefono válido" << std::endl;
	}while (input.empty());
	_contacts[_index].setPhoneNumber(input);
	do {
		std::cout << "Shhh!Cuentame un secreto ozzcuro" << std::endl;
		std::getline(std::cin, input);
		if (input.empty())
		std::cout	<< "Venga soy una tumba!ese chisme aqui!" << std::endl;
	}while (input.empty());
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

	if (_totalContacts == 0) // <-- Esto evita problemas si hay 0 contactos
	{
		std::cout	<< "No hay contactos guardados todavía. ¡Añade uno!"
					<< std::endl;
		return;
	}
	printTable();
	do {
		std::cout	<< "Elige un contacto para más detalles" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return;
		if (input.empty())
		{
			std::cout << "¿Me estás vacilando?"
						<< std::endl
						<< "> ";
		}
		else if ((input.length() != 1) || !(input[0] >= '0' && input[0] <= '7'))
			std::cout	<< "Perlita...uno válido a poder ser..." << std::endl;
		else
		{
			int	num = input[0] - '0';
			if (num >= _totalContacts)
				std::cout << "No existe todavía, dale tiempo" << std::endl;
			else
			{
				printDetails(num);
				valid = true;
			}
		}
	} while (!valid);
}



