# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_family()
{
	std::cout	<< "(WR)Default Constructor called"
				<< std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _family(type)
{
	std::cout	<< "(WR)Constructor called"
				<< std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other): _family(other._family)
{
	std::cout	<< "(WR)Copy Constructor called"
				<< std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	if (this != &other)
		_family = other._family;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout	<< "(WR)Destructor called"
				<< std::endl;
}

void	WrongAnimal::makeSound()const
{
	std::cout	<< "(WR)Some generic wrong animal sounds"
				<< std::endl;
}

std::string	WrongAnimal::getFamily()const
{
	return (_family);
}
