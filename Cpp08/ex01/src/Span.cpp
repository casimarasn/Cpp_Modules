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

void	Span::print() const
{
	if (_numbers.empty())
		std::cout << "(empty)" << std::endl;
	else
	{
		int size = 0;
		for (std::multiset<int>::const_iterator i = _numbers.begin(); i != _numbers.end(); ++i) {
			if (size > 100) {
				std::cout << "...";
				break ;
			}
			std::cout << *i << " ";
			size++;
		}
		std::cout << std::endl;
	}
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
	return (static_cast<unsigned int>(*_numbers.rbegin()) - static_cast<unsigned int>(*_numbers.begin()));
}


/*rbegin() es un iterador inverso que apunta directamente al último elemento,
así que se puede desreferenciar sin problema.*/