#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
 : AForm("RobotomyRequest", SIGN_GRADE, EXEC_GRADE),
   _target(target)
{
	std::cout << "RobotomyRequestForm Default Constructor Called\n";
}
	
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor Called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rRob)
: AForm(rRob), _target(rRob._target)
{
	std::cout << "RobotomyRequestForm Copy Constructor Called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rRob)
{
	if (this == &rRob)
		return (*this);
	std::cout << "RobotomyRequestForm Copy Assignment Operator Called\n";
	AForm::operator=(rRob);
	const_cast<std::string&>(_target) = rRob._target;
	return (*this);	
}
	

const std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw NoSignException();
	if (executor.getGrade() > getExecGrade())
		throw ExecGradeTooLowException();
	srand(time(NULL));
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully\n";
	else
		std::cout << _target << " has been failed to robotomized!\n";
}


std::ostream& operator<<(std::ostream &os, const  RobotomyRequestForm& rRob)
{
	std::cout << "Target : " << rRob.getTarget() << std::endl;
	std::cout << static_cast<const AForm&>(rRob);

	return (os);
}

