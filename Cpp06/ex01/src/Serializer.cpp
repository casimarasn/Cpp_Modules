#include "Serializer.hpp"

Serializer::Serializer() {}


Serializer::Serializer(const Serializer &Data)
{
	(void)Data;
}

Serializer	&Serializer::operator=(const Serializer &miData)
{
	(void)miData;
	return (*this);
}

Serializer::~Serializer() {}


/*Esto obliga al compilador a tratar el puntero directamente 
como un valor numérico entero, sin cambiar absolutamente 
nada de la memoria física.*/
static uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

/*proceso inverso exacto, transformando el número
de vuelta en un puntero a tu estructura*/
static Data*	deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

