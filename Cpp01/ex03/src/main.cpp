# include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

int	main ()
{
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA bob = HumanA("bob", club);

		bob.attack();
		club.setType("some other type of clubs");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");
		HumanB rob = HumanB("rob");
		rob.setWeapon(club);
		rob.attack();
		club.setType("some other type of clubs");
		rob.attack();
	}
	return (0);
}