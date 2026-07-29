#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class	WrongAnimal
{
	protected:
		std::string _family;

	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &other);
		WrongAnimal &operator=(WrongAnimal const &other);
		virtual ~WrongAnimal();
		virtual void	makeSound()const;
		std::string	getFamily()const;
};

#endif