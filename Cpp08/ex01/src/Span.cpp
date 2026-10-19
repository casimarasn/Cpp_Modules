#include "Span.hpp"
#include <stdexcept>

Span::Span():_N(0){}

Span::Span(const Span &other):_N(other._N), _numbers(other._numbers){}

Span::Span(unsigned int N): _N(N){}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span(){}

void	Span::addNumber(int num)
{
	if (_numbers.size() >= _N)
		throw std::runtime_error("Span is full");
	_numbers.insert(num);
}

unsigned int	Span::shortestSpan()const
{
	if (_numbers.size()< 2)
		throw std::runtime_error("Not enough numbers to find a span");
	std::multiset<int>::const_iterator	prev = _numbers.begin();
	std::multiset<int>::const_iterator curr = prev;
	++curr;
	unsigned int min = *curr - *prev;
	for (; curr != _numbers.end(); ++curr, ++prev)
	{
		unsigned int diff = *curr - *prev;
		if (diff < min)
			min = diff;
	}
	return(min);
}

unsigned int	Span::longestSpan()const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	return (*_numbers.rbegin() - *_numbers.begin());
}


/*rbegin() es un iterador inverso que apunta directamente al último elemento,
así que se puede desreferenciar sin problema.*/