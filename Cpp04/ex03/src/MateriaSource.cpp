# include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _slots()
{
	for(int i = 0; i < 4; i++)
		_slots[i] = NULL;
	std::cout	<< "(MAT)Default Constructor called"
				<< std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	for(int i = 0; i < 4; i++)
		_slots[i] = other._slots[i];
	*this = other;
	std::cout	<< "(MAT)Copy Constructor called"
				<< std::endl;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
		if(_slots[i])
			delete this->_slots[i];
	std::cout	<< "(MAT)Destructor called"
				<< std::endl;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for(int i = 0; i < 4; i++)
		{
			delete this->_slots[i];
			if (other._slots[i])
				this->_slots[i] = other._slots[i]->clone();
			else
				_slots[i] = NULL;
		}
		return(*this);
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for(int i = 0; i < 4; i++)
	{
		if(!_slots[i])
		{
			_slots[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for(int i = 0; i < 4; i++)
		if (_slots[i] && type == this->_slots[i]->getType())
			return (_slots[i]->clone());
	return (NULL);
}
