#ifndef _BUREAUCRAT_HPP
#define _BUREAUCRAT_HPP

#include <exception>
#include <string>

class	Bureaucrat
{
public:	
	class GradeTooHighException : public std::exception
	{
	private:
		const Bureaucrat& _rBu;	
		
		void inform() const;
	public:
		GradeTooHighException(const Bureaucrat& rBu);
		~GradeTooHighException() throw();
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	private:
		const Bureaucrat& _rBu;	
		
		void inform() const;
	public:
		GradeTooLowException(const Bureaucrat& rBu);
		~GradeTooLowException() throw();
		const char* what() const throw();
	};
private:
	enum {HIGHTEST_GRADE = 1, LOWEST_GRADE = 150};
	
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &rBru);
	Bureaucrat& operator=(const Bureaucrat &rBru);
	
	const std::string	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
};


std::ostream& operator<<(std::ostream &os, const Bureaucrat &rBu);

#endif
