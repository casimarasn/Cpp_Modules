# include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout	<< "Wrong instructions for Harl"
					<< std::endl;
		return (1);
	}
	Harl	instruction;

	instruction.complain(av[1]);
	return(0);
}
