#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw() {
			return "Value not found in container";
		}
};

template	<typename T>
typename T::iterator easyfind(T& container, int toFind)
{
	typename T::iterator result = std::find(container.begin(), container.end(), toFind)
	if (result == container.end())
		throw NotFoundException();
	return (result);


}

#endif


/* Standard Template Library
	iterador sabe como avanzar al siguiente elemento dentro de
	tu propio contenedor sin que tengamos que programar lógica.
	todos proporcionan dos iteradores clave_:
	.begin() primer elemento valido
	.end() espacio justo despues del ultimo elemento. marca el
	limite de salida por lo que nunca debemos intentar leer el valor de end
	
	algoritmo: std::find se indica donde empezar , donde terminar y que número buscar
	si encuentra devuelve iterador apuntando a ese numero exacto.
	si no tras recorrer todo te devuelve iterador que marca final.

	Manejo de errores: retornr error o lanzar excepcion. 

	Nota técnica importante:
Fíjate en la sintaxis typename T::iterator. Como el contenedor T es un tipo abstracto de una
plantilla, necesitamos anteponer la palabra typename para asegurarle al compilador que la
palabra iterator representa un "tipo de dato" anidado dentro de la clase T, y no una simple
variable.
*/