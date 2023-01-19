#ifndef _FORM_HPP
#define _FORM_HPP

#include <exception>
#include <string>
class Bureaucrat;

class	Form
{
public:
	class GradeTooHighException : public std::exception
	{
	private:
		const Form& _rForm;	
		
		void inform() const;
	public:
		GradeTooHighException(const Form& rForm);
		~GradeTooHighException() throw();
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	private:
		const Form& _rForm;	
		
		void inform() const;
	public:
		GradeTooLowException(const Form& rForm);
		~GradeTooLowException() throw();
		const char* what() const throw();
	};
private:
	enum {HIGHTEST_GRADE = 1, LOWEST_GRADE = 150};
	
	const int			_signGrade;
	const int			_execGrade;
	bool				_signed;
	const std::string	_name;	
public:
	Form();
	Form(const std::string& name, int signGrade, int execGrade);
	~Form();
	Form(const Form &rForm);
	Form& operator=(const Form &rForm);
	
	const std::string	getName() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	bool				isSigned() const;
	void				beSigned(const Bureaucrat& rBru);
};

std::ostream& operator<<(std::ostream &os, const Form &rForm);

#endif

