#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	ShrubberyCreationForm : public AForm
{
public:
	class	FileOpenException : public std::exception
	{
	private:
		const std::string _fileName;
	public:
		FileOpenException(const std::string& fileName);
		~FileOpenException() throw();
		const char* what() const throw();
	};
private:
	enum {SIGN_GRADE = 145, EXEC_GRADE = 137};
	const std::string	_target;
public:
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& rShr);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rShr);
	
	const std::string	getTarget() const;
	void				execute(Bureaucrat const & exectutor) const;				
};


std::ostream& operator<<(std::ostream &os, const  ShrubberyCreationForm& rShr);

#endif

