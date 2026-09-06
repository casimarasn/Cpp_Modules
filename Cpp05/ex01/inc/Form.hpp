#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class	Form
{
	private:

		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:

		Form();
		Form(const Form &other);
		Form( const std::string name, const int signGrade, int execGrade);
		Form &operator=(const Form &other);
		~Form();

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

std::ostream &operator<<(std::ostream &o, const Form &other);

#endif