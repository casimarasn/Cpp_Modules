#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template	<typename T>

void	swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
template <typename T>

const T&	min(const T& a, const T& b)
{
	return (a < b) ? a : b;
}

template <typename T>

const T&	max(const T& a, const T& b)
{
	return (a > b) ? a : b;
}
#endif



/*
template <typename T>
template: Es la palabra reservada que indica el inicio de la plantilla.
< >: Los símbolos de menor y mayor encierran los parámetros de la 
plantilla.

typename: Le avisa al compilador que "lo que viene a continuación es un 
tipo de dato abstracto". También puedes usar la palabra reservada class (
template <class T>); en este contexto significan exactamente lo mismo, 
pero typename suele ser más descriptivo.

T: Es el nombre que le damos a nuestro comodín. Se usa la mayúscula T (de 
Type) por convención universal, pero podrías llamarlo TipoDato o MiVariable 
si quisieras.
*/