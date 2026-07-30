#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal
{
	protected:
		std::string _family;

	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &other);
		Animal &operator=(Animal const &other);
		virtual ~Animal();
		virtual void	makeSound()const = 0;
		std::string	getFamily()const;
};

#endif