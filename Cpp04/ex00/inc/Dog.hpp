#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
class	Dog: public Animal
{
	protected:

	public:
		Dog();
		Dog(Dog const &other);
		Dog &operator=(Dog const &other);
		virtual ~Dog();
		virtual void	makeSound()const;
};


#endif