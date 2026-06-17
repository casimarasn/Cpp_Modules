# include "Zombie.hpp"

int	main()
{
	randomChump("foo");
	//nace
	//anuncia
	//muere

	Zombie *boo = newZombie("boo");
	boo->announce();
	delete boo;
	//nace
	//anuncia
	//delete : muere
	return(0);
}