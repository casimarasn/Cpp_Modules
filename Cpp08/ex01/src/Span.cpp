#include "Span.hpp"

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

