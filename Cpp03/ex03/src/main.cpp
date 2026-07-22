# include "DiamondTrap.hpp"

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

	{
		DiamondTrap	d("Bili");
		d.attack("Mili");
		d.WhoAmI();
	}
	return (0);
}
