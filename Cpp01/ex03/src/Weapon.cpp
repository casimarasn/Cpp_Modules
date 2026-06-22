# include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon()
{
	std::cout	<< _type << "eliminated"
				<< std::endl ;
}

void	Weapon::setType(std::string nType)
{
	_type = nType;
}

const std::string	Weapon::getType (void)
{
	return (_type);
}


