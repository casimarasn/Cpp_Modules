# include "Animal.hpp"

Animal::Animal():_family()
{
	std::cout	<< "Default Constructor called"
				<< std::endl;
}

Animal::Animal(std::string type): _family(type)
{
	std::cout	<< "Constructor called"
				<< std::endl;
}

Animal::Animal(Animal const &other): _family(other._family)
{
	std::cout	<< "Copy Constructor called"
				<< std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
	if (this != &other)
		_family = other._family;
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

std::string	Animal::getFamily()const
{
	return (_family);
}
