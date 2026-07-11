# include "Point.hpp"

Fixed	sign(Point p, Point const l1, Point const l2)
{
	return ((p.getX() - l2.getX()) * (l1.getY() - l2.getY()) -
		(l1.getX() - l2.getX()) * (p.getY() - l2.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1, d2, d3;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	if (d1 > 0 && d2 > 0 && d3 > 0)
		return (true);
	else if (d1 < 0 && d2 < 0 && d3 < 0)
		return (true);
	else
		return (false);
}
