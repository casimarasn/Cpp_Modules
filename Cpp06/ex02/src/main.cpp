#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main()
{
	// Plantamos la semilla aleatoria usando la hora actual
	std::srand(std::time(NULL));

	std::cout << "--- Generando objeto misterioso ---" << std::endl;
	Base* mistery = generate();

	std::cout << "\nIdentificando mediante PUNTERO:" << std::endl;
	identify(mistery);

	std::cout << "\nIdentificando mediante REFERENCIA:" << std::endl;
	identify(*mistery); // Le pasamos el valor desreferenciado para que actúe como referencia

	delete mistery; // Evitamos fugas de memoria
	return (0);
}

/*
El puntero usa la lógica de comprobación condicional
(¿eres igual a cero?).

La referencia usa la lógica de prueba y error
(intentarlo, fallar, capturar la excepción para que el programa
no aborte, y probar la siguiente opción).
*/