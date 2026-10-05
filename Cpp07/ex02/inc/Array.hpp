#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <exception>


template	<typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
				Array();
				Array(unsigned int n);
				Array(const Array &miArray);
		Array	&operator=(const Array &miArray);
		T		&operator[](unsigned int index);
		const T	&operator[](unsigned int index)const; //para arrays consteantes
				~Array();
		unsigned int size()const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Index out of bounds");
				}
		};
};

template	<typename T>
Array<T>::Array() : _array(NULL), _size(0) {};

template	<typename T>
Array<T>::Array(unsigned int n) : _size(n) 
{
	// Usamos new T[n]() con paréntesis al final.
	// Esto asegura que los tipos primitivos se inicialicen a 0 y 
	//los objetos llamen a su constructor por defecto.
	_array = new T[n]();
}

template	<typename T>
Array<T>::Array(const Array &miArray): _size(miArray._size)
{
	_array = new T[_size]();
	for (unsigned int i = 0; i < _size; i++)
	{
		_array[i] = miArray._array[i];
	}
}

template	<typename T>
Array<T> &Array<T>::operator=(const Array &miArray)
{
	if (this != &miArray)
	{
		if (_array != NULL)
			delete[]_array;
		_size = miArray._size;
		_array = new T[_size]();
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = miArray._array[i];
	}
	return(*this);
}

// Operador normal (permite lectura y escritura)
template	<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

// Operador constante (permite solo lectura)
template	<typename T>
const T&	Array<T>::operator[](unsigned int index)const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

template	<typename T>
Array<T>::~Array()
{
	if (_array != NULL)
		delete[]_array;
}

template	<typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}


#endif

/*un archivo tpp es un template plus plus. un archivo de texto estandar
para implementaciones de plantillas se escribe al final del hpp
*/