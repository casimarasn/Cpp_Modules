# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm(): _name(), _target(), _signGrade(1), _execGrade(1),  _signed(false)
{
	std::cout	<< "Default Constructor called"
				<< std::endl;
}

AForm::AForm(const std::string name, const std::string target, const int signGrade, int execGrade): 
		_name(name), _target(target), _signGrade(signGrade), _execGrade(execGrade)
{
	
	std::cout	<< "Constructor called"
				<< std::endl;
}

AForm::AForm(const AForm &other):_name(other._name), _target(other._target),
_signGrade(other._signGrade), _execGrade(other._execGrade), _signed(other._signed)
{
	std::cout	<< "Copy Constructor called"
				<< std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return(*this);
}

AForm::~AForm()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

const std::string	AForm::getName() const
{
	return(_name);
}

const std::string	AForm::getTarget() const
{
	return (_target);
}

int					AForm::getSignGrade() const 
{
	return(_signGrade);
}

int					AForm::getExecGrade() const
{
	return(_execGrade);
}

bool				AForm::getSigned() const
{
	return(_signed);
}

const char			*AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high, must be between 1 - 150");
}

const char			*AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is too low, must be between 1 - 150");
}

void				AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (_signGrade < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	_signed = true;
}

int					AForm::validateGrade(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
	return (grade);
}

const char			*AForm::FormNotSignedException::what() const throw()
{
	return ("the form is NOT signed");
}

void				AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_signed)
		throw FormNotSignedException();
	if (this->_execGrade < executor.getGrade())
		throw GradeTooLowException();
	this->execAction(executor);
}

std::ostream		&operator<<(std::ostream &o, const AForm &other)
{
	o	<< other.getName()
		<< ", grade to sign: "
		<< other.getSignGrade()
		<< " and grade to execute: "
		<< other.getExecGrade();

	if (other.getSigned())
		o	<< " IS signed.";
	else
		o	<< " IS NOT signed ";
	return (o);
}