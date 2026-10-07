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
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;

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
		static int					validateGrade(int grade);

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

/*static se recomienda usar por dos razones:

1. independencia del objeto: pertenecen a la clase en si, no a una instncia especifica.

2. las constantes deben inicializarse obligatoriamente en la lista de iniciacion del 
constructor Llamar a un método normal de la clase en ese instante puede ser arriesgado
porque el objeto no está completamente construido. Un método static se ejecuta de forma
segura sin depender del estado de un objeto incompleto.  */