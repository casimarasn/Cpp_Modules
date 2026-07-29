# include "WrongCat.hpp"


WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout	<< "(WrongCAT)Default Constructor called"
				<< std::endl;
}

WrongCat::WrongCat(WrongCat const &other)
{
	std::cout	<< "(WRCAT)Copy Constructor called"
				<< std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout	<< "(WRCAT)Destructor called"
				<< std::endl;
}

void	WrongCat::makeSound()const
{
	std::cout	<< "NOT MIAU"
				<< std::endl;
}