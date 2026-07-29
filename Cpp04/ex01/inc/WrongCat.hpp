#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	protected:

	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(WrongCat const &other);
		WrongCat &operator=(WrongCat const &other);
		virtual ~WrongCat();
		virtual void	makeSound()const;
		
};

#endif