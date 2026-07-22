# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():
		ClapTrap("unnamed_clap_name"),
		ScavTrap("unnamed_clap_name"),
		FragTrap("unnamed_clap_name")
{
	_name = "unnamed";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout	<< "(DIA) Default constructor called"
				<< std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout	<< "(DIA) Destructor called"
				<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
		ClapTrap(name + "_clap_name"),
		ScavTrap(name + "_clap_name"),
		FragTrap(name + "_clap_name")
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout	<< "(DIA) constructor called"
				<< std::endl;
}

DiamondTrap::DiamondTrap (const DiamondTrap &original):
		ClapTrap(original),
		ScavTrap(original),
		FragTrap(original)
{
	std::cout	<< "(DIA) Copy constructor called"
				<< std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &original)
{
	if (this != &original)
	{
		ScavTrap::operator=(original);
		FragTrap::operator=(original);
	}
	return (*this);
}

void	DiamondTrap::WhoAmI()
{
		std::cout	<< "(DIA) " << _name
					<< std::endl
					<< "(CLAP) " << FragTrap::_name
					<< std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

