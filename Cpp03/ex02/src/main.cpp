# include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	a("Pili");
	ClapTrap	b(a);
	ClapTrap	c;
	ScavTrap	d("Sidi");

	c = a;
	a.attack("Mili");
	b.beRepaired(100);
	c.takeDamage(5);
	d.guardGate();
	d.attack("Mili");
	return (0);
}
