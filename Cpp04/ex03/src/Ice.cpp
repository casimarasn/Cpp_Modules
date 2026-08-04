#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	// std::cout	<< "(ICE)Default Constructor called"
				// << std::endl;
}

Ice::Ice(Ice const &other): AMateria(other)
{
	// std::cout	<< "(ICE)Copy Constructor called"
				// << std::endl;
}

Ice::~Ice()
{
	// std::cout	<< "(ICE)Destructor called"
				// << std::endl;
}

Ice	&Ice::operator=(Ice const &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Ice*	Ice::clone()const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout	<< "* shoots an ice bolt at "
				<< target.getName()
				<< std::endl;
}
