#include "Serializer.hpp"

Serializer::Serializer() {}


Serializer::Serializer(const Serializer &Data)
{
	(void)Data;
}

Serializer	&Serializer::operator=(const Serializer &Data)
{
	(void)Data;
	return (*this);
}

Serializer::~Serializer() {}


/*Esto obliga al compilador a tratar el puntero directamente 
como un valor numérico entero, sin cambiar absolutamente 
nada de la memoria física.*/
uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

/*proceso inverso exacto, transformando el número
de vuelta en un puntero a tu estructura*/
 Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

/*reinterpret_cast
operador de conversion que instruye al compilador para 
reinterpretar el patron de bits subyacente de un tipo de dato
como si fuera otro distinto. No transforma datos ni genera
código ejecutable, es una operacion puramente en codigo de 
compilacion. su uso suspende el sistema de seguridad de tipos de C++
el estandar garantiza que si conviertes un puntero a un entero
con la capacidad suficiente y luego vuelta al mismo tipo, la
direccion de memoria resultante sera matematicamente identica

*/


/*uintptr_t
libreria stdint.h. numero entero sin signo magico que se adapta a las
direcciones 32bits o 64 bits. siempre garantza tener el mismo tamaño
que una direccion de memoria en la máquina donde se ejecute 
su uso previene el pointer truncation, fallo de corrupcion
de memoria fatal que ocurre si intentas almacenar una direccion
de 64 bits dentro de un int o long estandar que el compilador
haya definido con tamaño de 32 bits*/

/*static methods
pertenece al espacio de nombres de la propia clase como entidad 
logica, y no a las instancias creadas a partir de ella. a nivel
de memoria y compilacion carecen del puntero implicito this.
como consecuencia, no pueden acceder a variables miembro de 
instancia, pero a cambio pueden ser invocadas mediante el operador
de resolucion de ámbito sin resevar memoria en el heap o stack
para instanciar objeto previo.
permites que en el main llames directamente a Serializer sin tener
que crear un objeto Serializer.

*/