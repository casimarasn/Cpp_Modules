#include "Iter.hpp"

 template <typename T>
 void	printElement(const T& element)
 {
	std::cout	<< element << " ";
 }

 template <typename T>
 void	incrementElement(T& element)
 {
	element++;
 }

  int	main()
  {
	// Prueba con un array de enteros
	int intArray[] = {1, 2, 3, 4, 5};
	/*
	Calculamos la longitud del array: tamaño total en bytes de
	todo el array entre tamaño bytes un elemento.
	*/
	size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Array original: ";
	::iter(intArray, intLength, printElement<int>);
	std::cout << std::endl;

	std::cout << "Incrementando valores..." << std::endl;
	// Pasamos una función que modifica los elementos
	::iter(intArray, intLength, incrementElement<int>);

	std::cout << "Array modificado: ";
	::iter(intArray, intLength, printElement<int>);
	std::cout << std::endl;

	return 0;
  }