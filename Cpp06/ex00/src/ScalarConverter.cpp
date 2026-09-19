# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void)src;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& src)
{
	(void)src;
	return(*this);
}

ScalarConverter::~ScalarConverter(){}

void	ScalarConverter::convert(std::string& lit)
{
	bool	isPseudoLiteral = false;

	if (lit == "-inff" || lit == "+inff" || lit == "nanf")
	{
		isPseudoLiteral = true;
		// tipoDetectado = FLOAT;
		std::cout << "He detectado un pseudo-literal float!" << std::endl;
	}
	else if (lit == "-inf" || lit == "+inf" || lit == "nan") 
	{
		isPseudoLiteral = true;
		// tipoDetectado = DOUBLE;
		std::cout << "He detectado un pseudo-literal double!" << std::endl;
	}
	else if (lit.length() == 1 && !std::isdigit(lit[0]))
		// tipoDetectado = CHAR;
		std::cout << "He detectado un char!" << std::endl;
	else
	{
		for (int i = 0; i < lit.length(); i++)
		{
			/*saber si es int, char, float o double*/
			if (lit == )
		}

	}
}
