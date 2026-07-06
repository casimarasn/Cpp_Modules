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

Fixed::Fixed(const Fixed &original):_fixedValue(original.getRawBits()){}

Fixed&	Fixed::operator=(const Fixed &other)
{
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


Fixed a; dc 0
Fixed b(a); cc a= 0
Fixed c; dc 0, 

c = a; -> op c= a= 0