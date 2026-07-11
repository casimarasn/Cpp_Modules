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

Fixed::Fixed(const Fixed &original):_fixedValue(original._fixedValue)
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

int Fixed::getRawBits( void ) const
{
	std::cout	<< "getRawBits member function called"
				<< std::endl;
	return(this->_fixedValue);
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

Fixed&	Fixed::operator=(const Fixed &other)
{
	std::cout	<< "Copy assigment operator called"
				<< std::endl;
	if (&other != this)
		_fixedValue = other.getRawBits();
	return(*this);
}

std::ostream	&operator<<(std::ostream& str, const Fixed &other)
{
	str << other.toFloat();
	return (str);
}

Fixed	Fixed::operator+(const Fixed &other)const
{
	Fixed	result;

	result.setRawBits(_fixedValue + other._fixedValue);
	return(result);
}

Fixed	Fixed::operator-(const Fixed &other)const
{
	Fixed	result;

	result.setRawBits(_fixedValue - other._fixedValue);
	return(result);
}

Fixed	Fixed::operator/(const Fixed &other)const
{
	if (other._fixedValue == 0)
	{
		std::cerr	<< "Error: No Valid Calc"
					<< std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other)const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	this->_fixedValue++;
	return (*this);
}

Fixed	&Fixed::operator++(int)
{
	Fixed *result = this;

	this->_fixedValue++;
	return (*result);
}

Fixed	&Fixed::operator--(void)
{
	this->_fixedValue--;
	return (*this);
}

Fixed	&Fixed::operator--(int)
{
	Fixed *result = this;

	this->_fixedValue--;
	return (*result);
}

bool	Fixed::operator<(const Fixed &other)const
{
	return (_fixedValue < other._fixedValue);	
}

bool	Fixed::operator>(const Fixed &other)const
{
	return (_fixedValue > other._fixedValue);
}

bool	Fixed::operator<=(const Fixed &other)const
{
	return (_fixedValue <= other._fixedValue);
}

bool	Fixed::operator>=(const Fixed &other)const
{
	return (_fixedValue >= other._fixedValue);
}

bool	Fixed::operator==(const Fixed &other)const
{
	return (_fixedValue == other._fixedValue);
}

bool	Fixed::operator!=(const Fixed &other)const
{
	return (_fixedValue != other._fixedValue);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a > b ? b : a);

}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	return (a > b ? b : a);
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}
