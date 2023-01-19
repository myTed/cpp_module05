#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	RobotomyRequestForm : public AForm
{
private:
	enum {SIGN_GRADE = 72, EXEC_GRADE = 45};
	const std::string	_target;
public:
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& rRob);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rRob);
	
	const std::string	getTarget() const;
	void				execute(Bureaucrat const & exectutor) const;				
};


std::ostream& operator<<(std::ostream &os, const  RobotomyRequestForm& rRob);


#endif
