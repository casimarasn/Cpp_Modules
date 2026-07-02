#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class	Fixed
{
	private:
		int					_fixedValue;
		static const int	_fractionalBits;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &original);
		Fixed &operator=(const Fixed &other);
		int getRawBits( void ) const; 
		void setRawBits( int const raw);
};


#endif