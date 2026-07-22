#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
/* virtual*/
class	DiamondTrap: public ScavTrap, public FragTrap
{
	private:

	public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap (const DiamondTrap &original);
	DiamondTrap 

};
#endif