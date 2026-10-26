#include "Span.hpp"
# include <iostream>
# include <ctime>
# include <cstdlib>

int	main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.print();
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;

	std::cout << "Caso con un span lleno: intento añadir un num mas" << std::endl;
	sp.print();
	try
	{
		sp.addNumber(21);
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "Caso con un span vacio" << std::endl;
	Span vp = Span(0);
	vp.print();
	try
	{
	std::cout << "shortest: " << vp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "longest: " << vp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
			std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "Caso con un solo numero" << std::endl;
	Span one = Span(5);
	one.addNumber(42);
	one.print();
	try
	{
		std::cout << "shortest: " << one.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "longest: " << one.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "Caso con numeros repetidos" << std::endl;
	Span reps = Span(5);
	reps.addNumber(6);
	reps.addNumber(3);
	reps.addNumber(3);
	reps.addNumber(9);
	reps.addNumber(11);
	reps.print();
	try
	{
	std::cout << "shortest: " << reps.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "longest: " << reps.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
			std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "Caso con numeros negativos" << std::endl;
	Span nsp = Span(3);
	nsp.addNumber(-6);
	nsp.addNumber(-3);
	nsp.addNumber(2);
	nsp.print();
	try
	{
	std::cout << "shortest: " << nsp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "longest: " << nsp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
			std::cout << "Error: " << e.what() << std::endl;
	}

	Span msp(15000);
	std::multiset<int>bigVector;
	std::srand(std::time(NULL));
	for (int i = 0; i < 12000; i++)
	{
		bigVector.insert(std::rand());
	}
	msp.addNumber(bigVector.begin(), bigVector.end());
	msp.print();

	return (0);
}
