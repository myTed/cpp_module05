#ifndef _INTERN_HPP
#define _INTERN_HPP

#include "AForm.hpp"

class	Intern
{
private:
	enum {FORM_NUM = 3};
	static const char* formSortArry[FORM_NUM];
	typedef AForm* (Intern::*FUNC_PTR)(const std::string& target);
	FUNC_PTR _funcArry[FORM_NUM];
public:
	class	NoFoundFormException : public std::exception
	{
	private:
		const std::string _requestName;				
	public:
		NoFoundFormException(const std::string& name);
		~NoFoundFormException() throw();
		const char* what() const throw();
	};
private:
	AForm* makeShrubberyCreation(const std::string& target);
	AForm* makeRobotomyRequest(const std::string& target);
	AForm* makePresidentialPardon(const std::string& target);
public:
	Intern();
	~Intern();
	Intern(const Intern& rIn);
	Intern& operator=(const Intern& rIn);

	AForm* makeForm(const std::string& formName, const std::string& target);
};
#endif

