#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>

template <typename T>
class	MutantStack : public std::Stack<T>
{
	Public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack	&operator=(onst MutantStack &other);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
}


#endif