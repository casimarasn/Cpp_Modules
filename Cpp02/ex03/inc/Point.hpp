#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point();
		~Point();
		Point(Point const &other);
		Point(const float x, const float y);
		Fixed	getX()const;
		Fixed	getY()const;
		Point	&operator=(Point const &other);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);


#endif