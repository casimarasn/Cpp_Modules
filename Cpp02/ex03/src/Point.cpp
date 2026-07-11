# include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	std::cout	<< "Default constructor called"
				<< std::endl;
}

Point::~Point()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

Point::Point(Point const &other): _x(other._x), _y(other._y)
{
	std::cout	<< "Copy constructor called"
				<< std::endl;
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
	std::cout	<< "Constructor called"
				<< std::endl;
}

Fixed	Point::getX()const
{
	return (this->_x);
}

Fixed	Point::getY()const
{
	return (this->_y);
}

Point	&Point::operator=(Point const &other)
{
	(void)other;

	return (*this);
}


