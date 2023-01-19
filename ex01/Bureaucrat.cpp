#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

Bureaucrat::Bureaucrat()
: _name(""), _grade(LOWEST_GRADE)
{
	std::cout << "Bureaucrat Default Constructor Called\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
: _name(name), _grade(grade)
{
	std::cout << "Bureaucrat Non Default Constructor Called\n";
	if (_grade < HIGHTEST_GRADE)
		throw GradeTooHighException(*this);
	if (_grade > LOWEST_GRADE)
		throw GradeTooLowException(*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor " << _name << " Called\n";
}
	
Bureaucrat::Bureaucrat(const Bureaucrat &rBru)
: _name(rBru._name), _grade(rBru._grade)
{
	std::cout << "Bureaucrat Copy Constructor Called\n";
}
	
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rBru)
{
	if (this == &rBru)
		return (*this);
	std::cout << "Bureaucrat Copy Assignment Operator Called\n";
	const_cast<std::string&>(_name) = rBru._name;
	_grade = rBru._grade;
	return (*this);
}
	
const std::string	Bureaucrat::getName() const
{
	return (_name);
}
	
int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade == HIGHTEST_GRADE)
		throw GradeTooHighException(*this);
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == LOWEST_GRADE)
		throw GradeTooLowException(*this);
	++_grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat& rBu)
:_rBu(rBu)
{
	std::cout << "GradeTooHighException Non Default Constructor Called\n";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat& rBu)
: _rBu(rBu)
{
	std::cout << "GradeTooLowException Non Default Constructor Called\n";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
	std::cout << "GradeTooHighException Destructor Called\n";
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
	std::cout << "GradeTooLowException Destructor Called\n";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	inform();
	return "grade is too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	inform();
	return "grade is too low";
}


void Bureaucrat::GradeTooHighException::inform() const
{
	std::cout << "name : " << _rBu.getName() << std::endl;
	std::cout << "grade : " << _rBu.getGrade() << std::endl;
}

void Bureaucrat::GradeTooLowException::inform() const
{
	std::cout << "name : " << _rBu.getName() << std::endl;
	std::cout << "grade : " << _rBu.getGrade() << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat &rBu)
{
	std::cout << rBu.getName() << ", bureaucrat grade " << rBu.getGrade();
	return (os);
}


void Bureaucrat::signForm(Form &rForm) const
{
	try
	{
		rForm.beSigned(*this);
		std::cout << _name << " Signed " << rForm.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << rForm.getName();
		std::cout << " becasue " << e.what() << std::endl;
	}
}
