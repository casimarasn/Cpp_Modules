# include "Cat.hpp"

Cat::Cat(): Animal("Cat"),_brain(new Brain)
{
	std::cout	<< "(CAT)Default Constructor called"
				<< std::endl;
}

Cat::Cat(Cat const &other): Animal(other),_brain(new Brain(*other._brain))
{
	std::cout	<< "(CAT)Copy Constructor called"
				<< std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
	if (this != &other)
	{
		delete _brain;
		_brain = new Brain(*other._brain);
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout	<< "(CAT)Destructor called"
				<< std::endl;
}

void	Cat::makeSound()const
{
	std::cout	<< "MIAU"
				<< std::endl;
}

Brain* Cat::getBrain()const
{
	return (_brain);
}

