#ifndef CHARACTER_HPP
# define CHARACTER_HPP


# include "AMateria.hpp"
# include "ICharacter.hpp"



class Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria *_slots[4];
	public:

		Character();
		Character(Character const &other);
		Character(std::string name);
		Character &operator=(Character const &other);
		virtual ~Character();
		virtual std::string const &getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif