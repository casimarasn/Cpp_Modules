#include "Form.hpp"

Form::Form(): _name(), _signed(false), _signGrade(1), _execGrade(1)
{
	std::cout	<< "Default Constructor called"
				<< std::endl;
}

Form::Form(const Form &other):_name(other._name), _signed(other._signed),
		_signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout	<< "Copy Constructor called"
				<< std::endl;
}

Form::Form( const std::string name, const int signGrae, int execGrade)
{
	std::cout	<< "Constructor called"
				<< std::endl;
}

Form &Form::operator=(const Form &other)
{

}

Form::~Form()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

const std::string	Form::getName() const 
{

}

bool				Form::getSigned() const 
{

}

int					Form::getSignGrade() const 
{

}

int					Form::getExecGrade() const
{

}

void				Form::beSigned(Bureaucrat const &bureaucrat)
{

}

int					Form::validateGrade(int grade)
{

}
