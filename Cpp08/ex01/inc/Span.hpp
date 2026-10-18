#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class	Span
{
	private:
		unsigned int 		_N;
		std::vector<int>	_numbers;

	public:
						Span();
						Span(const Span &other);
						Span (unsigned int N);
		Span			&operator=(const Span &other);

						~Span();
		void			addNumber(unsigned int num);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};



#endif