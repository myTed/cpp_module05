#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
 : AForm("PresidentailPardon", SIGN_GRADE, EXEC_GRADE),
   _target(target)
{
	std::cout << "PresidentialPardonForm Default Constructor Called\n";
}
	
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor Called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rPre)
: AForm(rPre), _target(rPre._target)
{
	std::cout << "PresidentialPardonForm Copy Constructor Called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rPre)
{
	if (this == &rPre)
		return (*this);
	std::cout << "PresidentialPardonForm Copy Assignment Operator Called\n";
	AForm::operator=(rPre);
	const_cast<std::string&>(_target) = rPre._target;
	return (*this);	
}
	

const std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw NoSignException();
	if (executor.getGrade() > getExecGrade())
		throw ExecGradeTooLowException();
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox.\n";
}


std::ostream& operator<<(std::ostream &os, const  PresidentialPardonForm& rPre)
{
	std::cout << "Target : " << rPre.getTarget() << std::endl;
	std::cout << static_cast<const AForm&>(rPre);

	return (os);
}

