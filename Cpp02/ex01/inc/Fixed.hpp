#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_fixedValue;
		static const int	_fractionalBits;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &original);
		Fixed(const int integer);
		Fixed(const float pointNumber);
		Fixed &operator=(const Fixed &other);
		int getRawBits( void ) const; 
		void setRawBits( int const raw);
		float toFloat(void)const;
		int toInt(void)const;
};

std::ostream	

#endif