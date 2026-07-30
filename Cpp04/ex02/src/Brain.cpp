# include "Brain.hpp"

Brain::Brain(): _ideas()
{
	std::cout	<< "Default Constructor called"
				<< std::endl;
}

Brain::~Brain()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

Brain::Brain(Brain const &other)
{
	for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	std::cout	<< "Copy Constructor called"
				<< std::endl;
}

Brain	&Brain::operator=(Brain const &other)
{
	if (this != &other)
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	return (*this);
}

std::string Brain::getIdeas(int index)
{
	return(_ideas[index]);
}

void	Brain::setIdeas( int index, std::string const &ideas)
{
	_ideas[index] = ideas;
}
