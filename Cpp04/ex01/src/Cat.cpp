# include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout	<< "(CAT)Default Constructor called"
				<< std::endl;
}

Cat::Cat(Cat const &other)
{
	std::cout	<< "(CAT)Copy Constructor called"
				<< std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Cat::~Cat()
{
	std::cout	<< "(CAT)Destructor called"
				<< std::endl;
}

void	Cat::makeSound()const
{
	std::cout	<< "MIAU"
				<< std::endl;
}
