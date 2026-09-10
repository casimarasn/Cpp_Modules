# include "Bureaucrat.hpp"
# include "Form.hpp"


Bureaucrat::Bureaucrat(): _name(), _grade(1)
{
	std::cout	<< "Default constructor called"
				<< std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
	std::cout	<< "Copy constructor called"
				<< std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;

	std::cout	<< "Constructor called"
				<< std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}
Bureaucrat::~Bureaucrat()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

std::string Bureaucrat::getName()const
{
	return (_name);
}

int			Bureaucrat::getGrade()const
{
	return (_grade);
}

void		Bureaucrat::incrementGrade()
{
	if (this->_grade > 1)
		_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}
void		Bureaucrat::decrementGrade()
{
	if (this->_grade < 150)
		_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &other)
{
	o	<< other.getName()
		<< ", Bureaucrat grade "
		<< other.getGrade()
		<< "."
		<< std::endl;
	return (o);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: the grade is too high: it must be between 1 and 150\n");
}
const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: the grade is too low: it must be between 1 and 150\n");
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout	<< this->getName() << "signed "
					<< form.getName()
					<< std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout	<< this->getName() << "couldn't sign "
					<< form.getName()
					<< "because " << e.what()
					<< std::endl;
	}
}