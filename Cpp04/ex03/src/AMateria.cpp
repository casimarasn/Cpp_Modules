# include "AMateria.hpp"

AMateria::AMateria(): _type()
{
	std::cout	<< "(AMA)Default Constructor called"
				<< std::endl;
}

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout	<< "(AMA)Constructor called"
				<< std::endl;
}

AMateria::AMateria(AMateria const &other): _type(other._type)
{
	std::cout	<< "(AMA)Copy Constructor called"
				<< std::endl;
}

AMateria	&AMateria::operator=(AMateria const &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout	<< "(AMA)Destructor called"
				<< std::endl;
}

std::string AMateria::getType()const
{
	return (_type);
}

