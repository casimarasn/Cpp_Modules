# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("President", "", 25, 5)
{
	std::cout	<< "(PRESI)Default constructor called"
				<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm(other)
{	
	std::cout	<< "(PRESI)Copy constructor called"
				<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("President", target, 25, 5)
{
	std::cout	<< "(PRESI)Constructor called"
				<< std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout	<< "(PRESI)Destructor called"
				<< std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void	PresidentialPardonForm::execAction(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout	<< this->getTarget()
				<< " has been pardoned by Zaphod Beeblebrox."
				<< std::endl;
}
