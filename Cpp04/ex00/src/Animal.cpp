# include "Animal.hpp"

Animal::Animal():_type()
{
	std::cout	<< "Default Constructor called"
				<< std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout	<< "Constructor called"
				<< std::endl;
}

Animal::Animal(Animal const &other): _type(other._type)
{
	std::cout	<< "Copy Constructor called"
				<< std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
	if (this != &other)
		_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

void	Animal::makeSound()const
{
	std::cout	<< "Some generic animal sounds"
				<< std::endl;
}

std::string	Animal::getType()const
{
	return (_type);
}
