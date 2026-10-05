#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
# include <cstddef> // Para poder usar size_t

template	<typename T, typename Func>

void	iter(T* array, const size_t length, Func func)
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif