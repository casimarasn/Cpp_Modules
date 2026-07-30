# include "Dog.hpp"

Dog::Dog(): Animal("Dog"), _brain(new Brain)
{
	std::cout	<< "(DOG)Default Constructor called"
				<< std::endl;
}

Dog::Dog(Dog const &other):Animal(other), _brain(new Brain(*other._brain))
{
	std::cout	<< "(DOG)Copy Constructor called"
				<< std::endl;
}

Dog &Dog::operator=(Dog const &other) 
{
	if (this != &other)
	{
		delete _brain;
		_brain = new Brain(*other._brain);
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout	<< "(DOG)Destructor called"
				<< std::endl;
}

void	Dog::makeSound()const
{
	std::cout	<< "WUAU"
				<< std::endl;
}

Brain* Dog::getBrain()const
{
	return(_brain);
}
