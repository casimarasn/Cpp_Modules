# include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*nZombie = new Zombie(name);
	return (nZombie);
}
//return (new Zombie(name))