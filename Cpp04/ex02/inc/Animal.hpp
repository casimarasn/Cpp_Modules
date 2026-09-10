#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &other);
		Animal &operator=(Animal const &other);
		virtual ~Animal();
		virtual void	makeSound()const = 0;
		std::string	getType()const;
};

#endif

/*cuando una clase lleva uno o mas atributos igualados a 0 es abstracta
por lo tanto no instanciable*/