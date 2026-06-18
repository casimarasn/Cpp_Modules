# include "../includes/Zombie.hpp"

int	main(void)
{
	Zombie*	clan = zombieHorde(3, "boo");
	for (int i = 0; i < 3; i++)
		clan[i].announce();
	delete[] clan;
	return(0);
}