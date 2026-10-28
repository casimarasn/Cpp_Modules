#ifndef SPAN_HPP
# define SPAN_HPP


# include <iostream>
# include <set>
# include <iterator>
# include <stdexcept>



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
		void			print()const;
		unsigned int	shortestSpan()const;
		unsigned int	longestSpan()const;

		template	< typename T>
		void	addNumber(T begin, T end)
		{
			size_t range = std::distance(begin, end);
			if (range + _numbers.size() > _N)
				throw (std::runtime_error("error: Not enough space for this range"));
			_numbers.insert(begin, end);
		}

};



#endif