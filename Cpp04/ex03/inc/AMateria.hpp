#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

class	ICharacter;

class	AMateria
{
	protected:
		std::string	_type;
	
	public:
		AMateria();
		AMateria(AMateria const &other);
		virtual	~AMateria();
		AMateria(std::string const &type);
		AMateria	&operator=(AMateria const &other);
		virtual	AMateria* clone ()const = 0;
		virtual void	use(ICharacter &target) = 0;
		std::string getType()const;

};


#endif