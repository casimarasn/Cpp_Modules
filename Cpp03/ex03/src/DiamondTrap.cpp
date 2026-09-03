# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():
		ClapTrap("unnamed_clap_name"),
		ScavTrap("unnamed_clap_name"),
		FragTrap("unnamed_clap_name")
{
	_name = "unnamed";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
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
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout	<< "(DIA) constructor called"
				<< std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original):
		ClapTrap(original),
		ScavTrap(original),
		FragTrap(original),
		_name(original._name)
{
	std::cout	<< "(DIA) Copy constructor called"
				<< std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &original)
{
	if (this != &original)
	{
		_name = original._name;
		ScavTrap::operator=(original);
		FragTrap::operator=(original);
	}
	return (*this);
}

void	DiamondTrap::WhoAmI()
{
		std::cout	<< "(DIA) " << _name
					<< std::endl
					<< "(CLAP) " << ClapTrap::_name
					<< std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

/*cuando en los constructores de diamondtrap le damos 
los valores directos es porque como hemos hecho los padres 
virtuales y heredan de claptrap, se crean en orden y cuando 
toman los valores de las clases de los padres se han sobreescrito
porque hay una sola copia. por lo que se deben inicializar 
directamente.*/