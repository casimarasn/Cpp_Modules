#include "Form.hpp"

Form::Form(): _name(), _signed(false), _signGrade(1), _execGrade(1)
{
	std::cout	<< "Default Constructor called"
				<< std::endl;
}

Form::Form(const std::string name, const int signGrade, int execGrade):
	_name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	
	std::cout	<< "Constructor called"
				<< std::endl;
}

Form::Form(const Form &other):_name(other._name), _signed(other._signed),
		_signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout	<< "Copy Constructor called"
				<< std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return(*this);
}

Form::~Form()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

const std::string	Form::getName() const
{
	return(_name);
}

bool				Form::getSigned() const
{
	return(_signed);
}

int					Form::getSignGrade() const 
{
	return(_signGrade);
}

int					Form::getExecGrade() const
{
	return(_execGrade);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high, must be between 1 - 150");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low, must be between 1 - 150");
}

void				Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (_signGrade < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	_signed = true;
}

int					Form::validateGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
	return (grade);
}

