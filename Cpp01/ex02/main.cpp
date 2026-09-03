# include <iostream>
#include <string>

int	main()
{
	std::string	var = "HI THIS IS BRAIN";
	std::string *stringPTR = &var;
	std::string &stringREF = var;
/* direccion de memoria de la variable string*/
	std::cout	<< &var
				<< std::endl;
/* direccion de memoria almacenada por stringPTR*/
	std::cout	<< stringPTR
				<< std::endl;
/* direccion de memoria almacenada por stringREF*/
	std::cout	<< &stringREF
				<< std::endl;

/* valor de la variable string*/
	std::cout	<< var
				<< std::endl;
/* valor señalado por stringPTR*/
	std::cout	<< *stringPTR
				<< std::endl;
/* valor señalado por stringREF*/
	std::cout	<< stringREF
				<< std::endl;
	return (0);
}


