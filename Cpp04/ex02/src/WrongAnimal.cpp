# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type()
{
	std::cout	<< "(WR)Default Constructor called"
				<< std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
	std::cout	<< "(WR)Constructor called"
				<< std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other): _type(other._type)
{
	std::cout	<< "(WR)Copy Constructor called"
				<< std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other)
{
	if (this != &other)
		_type = other._type;
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

std::string	WrongAnimal::getType()const
{
	return (_type);
}
