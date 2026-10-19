#ifndef SPAN_HPP
# define SPAN_HPP


# include <set>

class	Span
{
	private:
		unsigned int 		_N;
		std::multiset<int>	_numbers;

	public:
						Span();
						Span(const Span &other);
						Span (unsigned int N);
		Span			&operator=(const Span &other);

						~Span();
		void			addNumber(int num);
		unsigned int	shortestSpan()const;
		unsigned int	longestSpan()const;
};



#endif