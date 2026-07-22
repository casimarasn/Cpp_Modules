# include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout	<< "(CLAP) Default constructor called"
				<< std::endl;
}

ClapTrap::ClapTrap(std::string	name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout	<< "(CLAP) Constructor called"
				<< std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout	<< "(CLAP) Destructor called"
				<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original): _name(original._name),
					_hitPoints(original._hitPoints),_energyPoints(original._energyPoints),
					_attackDamage(original._attackDamage)
{
	std::cout	<< "(CLAP) Copy Constructor called"
				<< std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &original)
{
	if (this != &original)
	{
		_name = original._name;
		_hitPoints = original._hitPoints;
		_energyPoints = original._energyPoints;
		_attackDamage = original._attackDamage;
	}
	return(*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints --;
		std::cout	<< "ClapTrap " << _name
		<< " attacks " << target
		<< ", causing " << _attackDamage
		<< " points of damage!"
		<< std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > 0 && _hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout	<< "ClapTrap " << _name
		<< " took " << amount
		<< " points of damage! "
		<< std::endl
		<< _hitPoints << " hp remaining..."
		<< std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout	<< "ClapTrap " << _name
		<< " took " << amount
		<< " points of energy! "
		<< std::endl
		<< _hitPoints << " hp gaining..."
		<< std::endl;
	}
}
