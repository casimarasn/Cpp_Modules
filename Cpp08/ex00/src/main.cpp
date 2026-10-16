#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <iterator>/*para usar distance*/

int	main(void)
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);

	std::vector<int>::iterator it = easyfind(v, 20);
	/**it desreferencia para obtener el valor */
	std::cout << "Encontrado: " << *it << std::endl;
	/*para saber donde apunta*/
	std::cout << "Posicion: " << std::distance(v.begin(), it) << std::endl;


	return(0);
}


/*td::vector es un contenedor de la STL: un array dinámico, es decir, 
una secuencia de elementos guardados uno detrás de otro en memoria, 
que crece solo cuando le añades cosas. Es como un array de C, pero sin 
que tengas que hacer malloc ni preocuparte del tamaño.*/