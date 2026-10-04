#ifndef ITER_HPP
# define ITER_hpp

#include <iostream>
# include <cstddef> // Para poder usar size_t

template	<typename T, typename Func>

void	iter(T* array, const size_t length, Func Func)
{
	for (int i = 0; i < length, i++)
		func(array[i]);
}



#endif