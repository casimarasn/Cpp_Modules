#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
class	DiamondTrap:
			virtual public ScavTrap,
			virtual public FragTrap
{
	private:
		std::string _name;
	public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap (const DiamondTrap &original);
	DiamondTrap &operator=(const DiamondTrap &original);
	void	WhoAmI();
	void	attack(const std::string &target);
};
#endif