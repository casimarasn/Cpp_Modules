#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() 
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout	<< "(SCAV) Default constructor called"
				<< std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout	<< "(SCAV) Destructor called"
				<< std::endl;

}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout	<< "(SCAV) Constructor called"
				<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original)
{
	std::cout	<< "(SCAV) Copy Constructor called"
				<< std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &original)
{
	if (this != &original)
		ClapTrap::operator=(original);
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout	<< "(SCAV) is now in Gate Keeper Mode"
				<< std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints --;
		std::cout	<< "ScavTrap " << _name
		<< " attacks " << target
		<< ", causing " << _attackDamage
		<< " points of damage!"
		<< std::endl;
	}
}