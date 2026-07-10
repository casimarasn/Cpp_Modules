# include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedValue(0)
{
	std::cout	<< "Default constructor called"
				<< std::endl;
}

Fixed::~Fixed()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

Fixed::Fixed(const Fixed &original):_fixedValue(original.getRawBits())
{
	std::cout	<< "Copy Constructor called"
				<< std::endl;
}

Fixed::Fixed(const int integer) : _fixedValue(integer << _fractionalBits)
{
	std::cout	<< "Int Constructor called"
				<< std::endl;
}

Fixed::Fixed(const float pointNumber): _fixedValue(roundf(pointNumber * 256.0f))
{
	std::cout	<< "Float Constructor called"
				<< std::endl;
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	std::cout	<< "Copy assigment operator called"
				<< std::endl;
	if (&other != this)
		_fixedValue = other.getRawBits();
	return(*this);
}

int Fixed::getRawBits( void ) const

{
	std::cout	<< "getRawBits member function called"
				<< std::endl;
	return(_fixedValue);
}

void Fixed::setRawBits( int const raw)
{
	_fixedValue = raw;
}

float Fixed::toFloat(void)const
{
	return((float)_fixedValue/256.0f);
}

int Fixed::toInt(void)const
{
	return(_fixedValue >> _fractionalBits);
}

std::ostream	&operator<<(std::ostream& str, const Fixed &other)
{
	str << other.
	std::cout	<< str
				<< std::endl;

}