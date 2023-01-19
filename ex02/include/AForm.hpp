#ifndef _AFORM_HPP
#define _AFORM_HPP

#include <exception>
#include <string>
class Bureaucrat;

class	AForm
{
public:
	class GradeTooHighException : public std::exception
	{
	private:
		const AForm& _rAForm;	
		
		void inform() const;
	public:
		GradeTooHighException(const AForm& rAForm);
		~GradeTooHighException() throw();
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	private:
		const AForm& _rAForm;
		
		void inform() const;
	public:
		GradeTooLowException(const AForm& rAForm);
		~GradeTooLowException() throw();
		const char* what() const throw();
	};
	
	class	ExecGradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	
	class	NoSignException : public std::exception
	{
	public:
		const char* what() const throw();
	};
private:
	enum {HIGHTEST_GRADE = 1, LOWEST_GRADE = 150};
	
	const int			_signGrade;
	const int			_execGrade;
	bool				_signed;
	const std::string	_name;	
public:
	AForm();
	AForm(const std::string& name, int signGrade, int execGrade);
	~AForm();
	AForm(const AForm &rAForm);
	AForm& operator=(const AForm &rAForm);
	
	const std::string	getName() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	bool				isSigned() const;
	void				beSigned(const Bureaucrat& rBru);
	virtual void		execute(Bureaucrat const & executor) const = 0;
	virtual const std::string getTarget() const = 0;	
};

std::ostream& operator<<(std::ostream &os, const AForm &rAForm);

#endif

