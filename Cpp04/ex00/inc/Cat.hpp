#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class	Cat: public Animal
{
	protected:

	public:
		Cat();
		Cat(std::string type);
		Cat(Cat const &other);
		Cat &operator=(Cat const &other);
		virtual ~Cat();
		virtual void	makeSound()const;
		
};

#endif