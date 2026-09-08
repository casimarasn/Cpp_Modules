#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		virtual void	execAction(Bureaucrat const & executor) const;

};

#endif