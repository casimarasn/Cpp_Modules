#include "phonebook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	input;

	std::cout	<< "Bienvenido a mi PhoneBook" 
				<< std::endl;
	std::cout	<< "Comandos disponibles: ADD, SEARCH, EXIT"
				<< std::endl;
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		if ( input == "EXIT")
			break ;
		else if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else
		{
			std::cout	<< "Comando no reconocido, prueba con ADD, SEARCH o EXIT"
						<< std::endl;
		}

	}
	return (0);
}