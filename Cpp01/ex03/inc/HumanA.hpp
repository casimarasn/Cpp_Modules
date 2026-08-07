#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"


class	HumanA
{
	private:
		std::string _name;
		Weapon&		_weapon;
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void	attack();
};

#endif

/* la diferencia entre Weapon& y Weapon* es que con * puede o no llevar arma, es decir, 
	el valor al inicializar puede ser NULL, sin embargo el Weapon& tiene que tener un valor 
	desde el principio, es decir, no ser NULL.
*/