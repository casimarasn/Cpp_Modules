#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	{
		ClapTrap	a("Pili");
		a.attack("Mili");
	}

	{
		ScavTrap	b("Sidi");
		b.attack("Mili");
		b.beRepaired(70);
		b.guardGate();
	}

	{
		FragTrap	c("Vanili");
		c.attack("Mili");
		c.beRepaired(70);
		c.highFivesGuys();
	}

	return (0);
}
