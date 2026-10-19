#include "Span.hpp"
# include <iostream>

int	main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "Caso con un span lleno" << std::endl;
	try
	{
		sp.addNumber(21);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	

	std::cout << "Caso con un span vacio" << std::endl;
	Span vp = Span(0);
	std::cout << vp.shortestSpan() << std::endl;
	std::cout << vp.longestSpan() << std::endl;

	std::cout << "Caso con numeros repetidos" << std::endl;
	Span reps = Span(5);
	reps.addNumber(6);
	reps.addNumber(3);
	reps.addNumber(3);
	reps.addNumber(9);
	reps.addNumber(11);
	std::cout << reps.shortestSpan() << std::endl;
	std::cout << reps.longestSpan() << std::endl;

	std::cout << "Caso con numeros negativos" << std::endl;
	Span nsp = Span(3);
	nsp.addNumber(-6);
	nsp.addNumber(-3);
	nsp.addNumber(2);
	std::cout << nsp.shortestSpan() << std::endl;
	std::cout << nsp.longestSpan() << std::endl;


	return (0);
}
