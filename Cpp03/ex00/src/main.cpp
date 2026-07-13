# include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("Pili");
	ClapTrap	b(a);
	ClapTrap	c;

	c = a;
	a.attack("Mili");
	b.beRepaired(100);
	c.takeDamage(5);
	return (0);
}
