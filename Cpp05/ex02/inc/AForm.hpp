#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class	AForm
{
	private:

		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:

		AForm();
		AForm(const AForm &other);
		AForm( const std::string name, const int signGrade, int execGrade);
		AForm &operator=(const AForm &other);
		~AForm();

		const std::string	getName() const ;
		bool				getSigned() const ;
		int					getSignGrade() const ;
		int					getExecGrade() const ;

		void				beSigned(Bureaucrat const &bureaucrat);
		int					validateGrade(int grade);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, const AForm &other);

#endif