#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP


#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <iomanip>

class ScalarConverter
{
	private:
		// Orthodox Canonical Form oculta para evitar instanciación
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter	&operator=(const ScalarConverter& src);
		~ScalarConverter();

	public:
		static void	convert(std::string& lit);


}


#endif