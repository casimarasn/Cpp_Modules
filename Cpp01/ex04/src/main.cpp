# include "File.hpp"

int	main (int ac, char **av)
{
	if (ac != 4)
	{
		std::cout	<< "Wrong number of arguments"
					<< std::endl;
		return (1);
	}
	File	doc(av[1], av[2], av[3]);
	doc.replace();
	std::cout	<< av[1]
				<< std::endl;
	return(0);
}