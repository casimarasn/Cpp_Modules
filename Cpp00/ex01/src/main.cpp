#include "phonebook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	input;

	std::cout	<< "Welcome to my Phonebook" 
				<< std::endl;
	std::cout	<< "Available Comands: ADD, SEARCH, EXIT"
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
			std::cout	<< "Comand not recognised, try with ADD, SEARCH o EXIT"
						<< std::endl;
		}
	}
	return (0);
}