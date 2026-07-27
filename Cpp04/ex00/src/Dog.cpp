# include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout	<< "(DOG)Default Constructor called"
				<< std::endl;
}

Dog::Dog(Dog const &other)
{
	std::cout	<< "(DOG)Copy Constructor called"
				<< std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Dog::~Dog()
{
	std::cout	<< "(DOG)Destructor called"
				<< std::endl;
}

void	Dog::makeSound()const
{
	std::cout	<< "WUAU"
				<< std::endl;
}
