#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <iterator> /*para usar distance*/

int	main(void)
{
	std::cout << "cadena vector de prueba: " << std::endl;
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);

	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::vector<int>::iterator it = easyfind(v, 20);
	/* *it desreferencia para obtener el valor */
	std::cout << "Encontrado: " << *it << std::endl;
	/*para saber donde apunta*/
	std::cout << "Posicion: " << std::distance(v.begin(), it) << std::endl;

	std::cout << "Camino del error: " << std::endl;
	try
	{
		std::cout << "prueba con el 99" << std::endl;
		std::vector<int>::iterator it2 = easyfind(v, 99);
		std::cout << "Encontrado: " << *it2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "cadena list de prueba" << std::endl;
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(2);
	for (std::list<int>::iterator i = l.begin(); i != l.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	
	std::list<int>::iterator itl = easyfind(l, 2);
	std::cout << "Lista, encontrado: " << *itl << std::endl;
	std::cout << "Posicion: " << std::distance(l.begin(), itl) << std::endl;
	
	std::cout << "Camino del error: " << std::endl;
	try
	{
		std::cout << "prueba con el 5" << std::endl;
		std::list<int>::iterator it2 = easyfind(l, 5);
		std::cout << "Encontrado: " << *it2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "cadena const list de prueba" << std::endl;
	const std::list<int> cl(l);
	for (std::list<int>::const_iterator i = cl.begin(); i != cl.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::list<int>::const_iterator itc = easyfind(cl, 3);
	std::cout << "Const, encontrado: " << *itc << std::endl;
	std::cout << "Camino del error: " << std::endl;
	try
	{
		std::cout << "prueba con el 42" << std::endl;
		std::list<int>::const_iterator it2 = easyfind(cl, 42);
		std::cout << "Encontrado: " << *it2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return(0);
}


/*td::vector es un contenedor de la STL: un array dinámico, es decir, 
una secuencia de elementos guardados uno detrás de otro en memoria, 
que crece solo cuando le añades cosas. Es como un array de C, pero sin 
que tengas que hacer malloc ni preocuparte del tamaño.*/

/*Qué deberías poder explicar en la defensa
Por qué easyfind es un template y funciona con vector y list sin cambios.
Para qué sirve typename en typename T::iterator.
Por qué end() no se desreferencia.
Por qué hay dos sobrecargas (T& y const T&).
Por qué usas std::runtime_error y no una clase propia.
*/