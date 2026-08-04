# include "Character.hpp"

Character::Character(): _name(""), _slots()
{
	// std::cout	<< "(CHAR)Default Constructor called"
				// << std::endl;
}

Character::Character(std::string name): _name(name), _slots()
{
	// std::cout	<< "(CHAR)Constructor called"
				// << std::endl;
}

Character::Character(Character const &other): _name(other._name)
{
	for(int i = 0; i < 4; i++)
		_slots[i] = NULL;
	for(int i = 0; i < 4; i++)
		if (other._slots[i])
			_slots[i] = other._slots[i]->clone();
	// std::cout	<< "(CHAR)Copy Constructor called"
				// << std::endl;
}

Character &Character::operator=(Character const &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
			_slots[i] = other._slots[i]->clone();
	}
	return(*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_slots[i])
			delete _slots[i];
	// std::cout	<< "(CHAR)Destructor called"
				// << std::endl;
}

std::string const &Character::getName() const
{
	return(_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_slots[i])
		{
			_slots[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0  && idx < 4)
		if (_slots[idx])
			_slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0  && idx < 4)
		if (_slots[idx])
			_slots[idx]->use(target);
}
