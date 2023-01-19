#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form()
: _signGrade(LOWEST_GRADE), _execGrade(LOWEST_GRADE), _signed(false), _name("")
{
	std::cout << "Form Default Constructor Called\n";
}

Form::Form(const std::string& name, int signGrade, int execGrade)
:  _signGrade(signGrade), _execGrade(execGrade), _signed(false), _name(name)
{
	std::cout << "Form Non Default Constructor Called\n";
	if ((_signGrade < HIGHTEST_GRADE) || (_execGrade < HIGHTEST_GRADE))
		throw GradeTooHighException(*this);
	if ((_signGrade > LOWEST_GRADE || (_execGrade > LOWEST_GRADE)))
		throw GradeTooLowException(*this);
}

Form::~Form()
{
	std::cout << "Form Destructor " << _name << " Called\n";
}

Form::Form(const Form &rForm)
: _signGrade(rForm._signGrade),
 _execGrade(rForm._execGrade),
 _signed(rForm._signed),
_name(rForm._name)
{
	std::cout << "Form Copy Constructor Called\n";
}


Form& Form::operator=(const Form &rForm)
{
	if (this == &rForm)
		return (*this);
	std::cout << "Form Copy Assignment Operator Called\n";
	const_cast<std::string&>(_name) = rForm._name;
	const_cast<int&>(_signGrade) = rForm._signGrade;
	const_cast<int&>(_execGrade) = rForm._execGrade;
	_signed = rForm._signed;
	return (*this);
}

const std::string	Form::getName() const
{
	return (_name);
}
	
int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecGrade() const
{
	return (_execGrade);
}

bool Form::isSigned() const
{
	return (_signed);
}


void	Form::beSigned(const Bureaucrat& rBru)
{
	if (rBru.getGrade() > _signGrade)
		throw GradeTooLowException(*this);
	_signed = true;
}


Form::GradeTooHighException::GradeTooHighException(const Form& rForm)
:_rForm(rForm)
{
	std::cout << "GradeTooHighException Non Default Constructor Called\n";
}

Form::GradeTooLowException::GradeTooLowException(const Form& rForm)
: _rForm(rForm)
{
	std::cout << "GradeTooLowException Non Default Constructor Called\n";
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "GradeTooHighException Destructor Called\n";
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "GradeTooLowException Destructor Called\n";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade is too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}


void Form::GradeTooHighException::inform() const
{
	std::cout << "name : " << _rForm.getName() << std::endl;
	std::cout << "signGrade : " << _rForm.getSignGrade() << std::endl;
	std::cout << "execGrade : " << _rForm.getExecGrade() << std::endl;
}

void Form::GradeTooLowException::inform() const
{
	std::cout << "name : " << _rForm.getName() << std::endl;
	std::cout << "signGrade : " << _rForm.getSignGrade() << std::endl;
	std::cout << "execGrade : " << _rForm.getExecGrade() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form &rForm)
{
	std::cout << "Form name : " << rForm.getName() << std::endl;
	std::cout << "Form signGrade :" << rForm.getSignGrade() << std::endl;
	std::cout << "Form execGrade :" << rForm.getExecGrade() << std::endl;
	std::cout << "Signed : " << (rForm.isSigned()? "true" : "false") << std::endl;
	return (os);
}
