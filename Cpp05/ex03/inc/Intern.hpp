# ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>

class AForm;

class	Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		Intern &operator=(Intern const &other);
		~Intern();
		AForm	*makeForm(std::string forName, std::string formTarget);
};

#endif