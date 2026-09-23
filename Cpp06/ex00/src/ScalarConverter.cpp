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

void	ScalarConverter::convert(const std::string& lit)
{
	bool	isPseudoLiteral = false;
	e_type	tDetected = NONE;

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
	{
		// tipoDetectado = CHAR;
		std::cout << "He detectado un char!" << std::endl;
	}
	else
	{
		bool hasDot = false;
		bool hasF = false;
		bool isInvalid = false;
		size_t len = lit.length();
		for (int i = 0; i < lit.length(); i++)
		{
			/*saber si es int, char, float o double*/
			if (std::isdigit(lit[i]))
				continue ;
			else if (i > 0 && (lit[i] == '+' || lit[i] == '-'))
			{
				isInvalid = true;
				break ;
			}
			else if (lit[i] == '.')
			{
				if (!hasDot)
					hasDot = true;
				else
				{
					isInvalid = true;
					break ;
				}
			}
			else if (lit[i] == 'f')
			{
				if(i == len - 1)
					hasF = true;
				else
				{
					isInvalid = true;
					break ;
				}
			}
			else
			{
				isInvalid = true;
				break ;
			}
		}
		if (isInvalid == true)
			tDetected = IMPOSSIBLE;
		else if (hasF == true)
			tDetected = FLOAT;
		else if (hasDot)
			tDetected = DOUBLE;
		else
			tDetected = INT;
	}
}
