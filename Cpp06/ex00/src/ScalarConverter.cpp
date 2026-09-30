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
		tDetected = FLOAT;
	}
	else if (lit == "-inf" || lit == "+inf" || lit == "nan") 
	{
		isPseudoLiteral = true;
		tDetected = DOUBLE;
	}
	else if (lit.length() == 1 && !std::isdigit(lit[0]))
		tDetected = CHAR;
	else
	{
		bool hasDot = false;
		bool hasF = false;
		bool isInvalid = false;
		size_t len = lit.length();
		for (size_t i = 0; i < lit.length(); i++)
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
	switch (tDetected)
	{
		case IMPOSSIBLE:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
		case CHAR:
		{
			char c = lit[0];
			int i = static_cast<int>(c);
			float f = static_cast<float>(c);
			double d = static_cast<double>(c);
			std::cout << "char: '" << c << "'" << std::endl;
			std::cout << "int: " << i << std::endl;
			
			// Como un char casteado a float/double siempre da un número entero (ej. 'a' -> 97),
			// std::cout omitirá los decimales por defecto. Podemos forzarlos así:
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;
			break ;
		}
		case INT:
		{
			char *endptr;
			long longVal = std::strtol(lit.c_str(), &endptr, 10);
			if (longVal > std::numeric_limits<int>::max() || 
				longVal < std::numeric_limits<int>::min() || *endptr != '\0')
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
			}
			else
			{
				int i = static_cast<int>(longVal);
				char c = static_cast<char>(i);
				
				if (i >= 0 && i <= 127 && std::isprint(i))
					std::cout << "char: '" << c << "'" << std::endl;
				else if (i >= 0 && i <= 127)
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: impossible" << std::endl;
				std::cout << "int: " << i << std::endl;
				std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
				std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
			}
			break ;
		}
		case FLOAT:
		{
			char *endptr;
			float f = std::strtof(lit.c_str(), &endptr);
			
			if (isPseudoLiteral || f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
			}
			else
			{
				int i = static_cast<int>(f);
				if (i >= 0 && i <= 127 && std::isprint(i))
					std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
				else if (i >= 0 && i <= 127)
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: impossible" << std::endl;
				
				std::cout << "int: " << i << std::endl;
			}
			
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
			break ;
		}
		case DOUBLE:
		{
			char *endptr;
			double d = std::strtod(lit.c_str(), &endptr);
			
			if (isPseudoLiteral || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
			}
			else
			{
				int i = static_cast<int>(d);
				if (i >= 0 && i <= 127 && std::isprint(i))
					std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
				else if (i >= 0 && i <= 127)
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: impossible" << std::endl;
				
				std::cout << "int: " << i << std::endl;
			}
			
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
			break ;
		}
		default:
			break;
	}
}

/*COSAS A TENER EN CUENTA:

nan				→ "Not a Number", representa un resultado sin sentido matemático
				(ej. 0.0/0.0). Versión double.

nanf			→ lo mismo pero como literal de tipo float (la f al final
				indica "float", igual que en 4.2f).

inf / +inf		→ infinito positivo (double). El + es opcional/redundante,
				es solo notación.

-inf 			→ infinito negativo (double).

inff / +inff	→ infinito positivo, versión float.

-inff			→ infinito negativo, versión float.*/



/*FUNCIONES UTILES:

strtod	→		devuelve double. Sirve también para detectar "nan"/"inf"
				automáticamente si quisieras (aunque tú ya los gestionas aparte
				por comparación exacta).

strtof	→		igual pero devuelve float directamente (útil si quieres parsear
				ya como float sin pasar por double y perder precisión de forma distinta).

strtol	→		para enteros. Firma: long strtol(const char *str, char **endptr, int base)
				— el tercer parámetro es la base numérica (usarías 10 para decimal).
				Devuelve long, no int, así que tendrás que comprobar tú mismo si el
				valor cabe en rango de int.
static_cast →	cuendo existe una relacion logica o matematica conocida entre dos tipos
				de datos. SI transforma datos subyacentes. cuando se utiliza el ompilador inyecta
				instrucciones de CPU reales para traducir el patrón de bits de un formato a otro
				garantizando valor semantico mantenido en la medida de lo posible.
				en el ex static_cast destruye el patron de bits original, calcula como escribe
				el numero en int y escribe patron de bits totalmente nuevo en la memoria.
*/

/*ejemplos validos e invalidos de como debe funcionar el programa:

./convert 'a' / a
char: 'a'
int: 97
float: 97.0f
double: 97.0


./convert '\n'

./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0


./convert -42
char: impossible
int: -42
float: -42.0f
double: -42.0


./convert 1234567890123.0
char: impossible
int: impossible
float: impossible
double: 1234567890123.0


./convert +inf
char: impossible
int: impossible
float: inff
double: inf


./convert -4.2f
char: impossible
int: -4
float: -4.2f
double: -4.2

./convert hello
*/