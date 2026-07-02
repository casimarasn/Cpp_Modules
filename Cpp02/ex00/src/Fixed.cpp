# include "Fixed.hpp"

_fractionalBits{}

Fixed::Fixed() : _fixedValue(0){}

Fixed::~Fixed()
{
	std::cout	<< "Everything deleted"
				<< std::endl;
}

Fixed::Fixed(const Fixed &original)
{

}

Fixed Fixed::&operator=(const Fixed &other)
{

}

int Fixed::getRawBits( void ) const
{

}

void Fixed::setRawBits( int const raw)
{

}
