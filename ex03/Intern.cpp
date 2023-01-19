#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

const char* Intern::formSortArry[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidentail Pardon"
	};

Intern::Intern()
{
	std::cout << "Intern Default Constructor Called\n";
	_funcArry[0] = &Intern::makeShrubberyCreation;
	_funcArry[1] = &Intern::makeRobotomyRequest;
	_funcArry[2] = &Intern::makePresidentialPardon;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called\n";
}
	
Intern::Intern(const Intern& rIn)
{
	std::cout << "Intern Copy Constructor Called\n";
	for (int idx = 0; idx < FORM_NUM; idx++)
		_funcArry[idx] = rIn._funcArry[idx];
}
	
Intern& Intern::operator=(const Intern& rIn)
{
	std::cout << "Intern Copy Assignment Operator Called\n";
	(void)rIn;
	return (*this);
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	for (int idx = 0; idx < FORM_NUM; idx++)
	{
		if (formName == std::string(formSortArry[idx]))
			return ((this->*_funcArry[idx])(target));
	}
	throw NoFoundFormException(formName);
}

AForm* Intern::makeShrubberyCreation(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequest(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}
	
AForm* Intern::makePresidentialPardon(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}


Intern::NoFoundFormException::NoFoundFormException(const std::string& name)
:_requestName(name)
{
	std::cout << "NoFoundFormException Contruction Called\n";
}

Intern::NoFoundFormException::~NoFoundFormException() throw()
{
	std::cout << "NoFoundFormException Destruction Called\n";
}


const char* Intern::NoFoundFormException::what() const throw()
{
	std::cout << "[ " << _requestName << " ]";
	return (" not found such name");
}
