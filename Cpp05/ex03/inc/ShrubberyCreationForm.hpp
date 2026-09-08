#ifndef SHUBBERYCREATIONFORM_HPP
# define SHUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		class FileCreationException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		// std::string		getTarget() const;
		virtual void	execAction(Bureaucrat const & executor) const;

};

#endif
