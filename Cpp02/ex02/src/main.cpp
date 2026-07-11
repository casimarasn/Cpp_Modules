# include "Point.hpp"

int	main(void)
{
	Point const	a(0.0f, 0.0f);
	Point const	b(10.0f, 0.0f);
	Point const	c(5.0f, 10.0f);

	//Caso 1:
	Point const	into(5.0f, 3.0f);

	//Caso 2:
	Point const	out(12.0f, 5.0f);

	//Caso 3:
	Point const	inLine(5.0f, 0.0f);

	std::cout	<< "Point in (expected: 1): "
				<< bsp(a, b, c, into) << std::endl;
	std::cout	<< "Point out (expected: 0): "
				<< bsp(a, b, c, out) << std::endl;
	std::cout	<< "Point in vector (expected: 0): "
				<< bsp(a, b, c, inLine) << std::endl;

	return (0);
}
