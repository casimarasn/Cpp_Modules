# include "Harl.hpp"

int	getLevel(std::string level)
{
	std::string instructions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
		if (instructions[i] == level)
			return (i);
	return (-1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout	<< "Wrong instructions for Harl"
					<< std::endl;
		return (1);
	}
	Harl	instruction;

	int	i = getLevel(av[1]); 

	switch (i)
	{
		case 0: 
			instruction.complain("DEBUG");
		case 1:
			instruction.complain("INFO");
		case 2:
			instruction.complain("WARNING");
		case 3:
		{
			instruction.complain("ERROR");
			break ;
		}
		default:
		{
			std::cout	<< "Wrong instructions for Harl"
						<< std::endl;
			break ;
		}
	}
	return(0);
}
