#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm()
: _signGrade(LOWEST_GRADE), _execGrade(LOWEST_GRADE), _signed(false), _name("")
{
	std::cout << "AForm Default Constructor Called\n";
}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
:  _signGrade(signGrade), _execGrade(execGrade), _signed(false), _name(name)
{
	std::cout << "AForm Non Default Constructor Called\n";
	if ((_signGrade < HIGHTEST_GRADE) || (_execGrade < HIGHTEST_GRADE))
		throw GradeTooHighException(*this);
	if ((_signGrade > LOWEST_GRADE || (_execGrade > LOWEST_GRADE)))
		throw GradeTooLowException(*this);
}

AForm::~AForm()
{
	std::cout << "AForm Destructor " << _name << " Called\n";
}

AForm::AForm(const AForm &rAForm)
: _signGrade(rAForm._signGrade),
 _execGrade(rAForm._execGrade),
 _signed(rAForm._signed),
_name(rAForm._name)
{
	std::cout << "AForm Copy Constructor Called\n";
}


AForm& AForm::operator=(const AForm &rAForm)
{
	if (this == &rAForm)
		return (*this);
	std::cout << "AForm Copy Assignment Operator Called\n";
	const_cast<std::string&>(_name) = rAForm._name;
	const_cast<int&>(_signGrade) = rAForm._signGrade;
	const_cast<int&>(_execGrade) = rAForm._execGrade;
	_signed = rAForm._signed;
	return (*this);
}

const std::string	AForm::getName() const
{
	return (_name);
}
	
int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecGrade() const
{
	return (_execGrade);
}

bool AForm::isSigned() const
{
	return (_signed);
}


void	AForm::beSigned(const Bureaucrat& rBru)
{
	if (rBru.getGrade() > _signGrade)
		throw GradeTooLowException(*this);
	_signed = true;
}


AForm::GradeTooHighException::GradeTooHighException(const AForm& rAForm)
:_rAForm(rAForm)
{
	std::cout << "GradeTooHighException Non Default Constructor Called\n";
}

AForm::GradeTooLowException::GradeTooLowException(const AForm& rAForm)
: _rAForm(rAForm)
{
	std::cout << "GradeTooLowException Non Default Constructor Called\n";
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "GradeTooHighException Destructor Called\n";
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "GradeTooLowException Destructor Called\n";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade is too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}


void AForm::GradeTooHighException::inform() const
{
	std::cout << "name : " << _rAForm.getName() << std::endl;
	std::cout << "signGrade : " << _rAForm.getSignGrade() << std::endl;
	std::cout << "execGrade : " << _rAForm.getExecGrade() << std::endl;
}

void AForm::GradeTooLowException::inform() const
{
	std::cout << "name : " << _rAForm.getName() << std::endl;
	std::cout << "signGrade : " << _rAForm.getSignGrade() << std::endl;
	std::cout << "execGrade : " << _rAForm.getExecGrade() << std::endl;
}


const char* AForm::ExecGradeTooLowException::what() const throw()
{
	return ("ExecGrade is Too low");
}

const char* AForm::NoSignException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm &rAForm)
{
	std::cout << "AForm name : " << rAForm.getName() << std::endl;
	std::cout << "AForm signGrade :" << rAForm.getSignGrade() << std::endl;
	std::cout << "AForm execGrade :" << rAForm.getExecGrade() << std::endl;
	std::cout << "Signed : " << (rAForm.isSigned()? "true" : "false") << std::endl;
	return (os);
}
