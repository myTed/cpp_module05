#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	PresidentialPardonForm : public AForm
{
private:
	enum {SIGN_GRADE = 25, EXEC_GRADE = 5};
	const std::string	_target;
public:
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& rPre);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rPre);
	
	const std::string	getTarget() const;
	void				execute(Bureaucrat const & exectutor) const;				
};


std::ostream& operator<<(std::ostream &os, const  PresidentialPardonForm& rPre);


#endif
