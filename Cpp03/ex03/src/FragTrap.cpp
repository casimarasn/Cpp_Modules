# include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout	<< "(FRAG) Default constructor called"
				<< std::endl;
}

FragTrap::~FragTrap()
{
	std::cout	<< "(FRAG) Destructor called"
				<< std::endl;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout	<< "(FRAG) constructor called"
				<< std::endl;
}

FragTrap::FragTrap(const FragTrap &original): ClapTrap(original)
{
	std::cout	<< "(FRAG) Copy constructor called"
				<< std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &original)
{
	if (this != &original)
	{
		ClapTrap::operator=(original);
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout	<< "(FRAG) High Five Guys!"
				<< std::endl;
}