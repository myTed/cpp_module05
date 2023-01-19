#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main(void)
{
	{
		try
		{
			Bureaucrat person("kyolee", 120);
			std::cout << person << std::endl;
			Bureaucrat person2("kyolee2", 10);
		
		
			person2.decrementGrade();
			std::cout << "name : " << person2.getName() << std::endl;
			std::cout << "grade: " << person2.getGrade() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	{
		std::cout << "\n\n=========Form test==========\n\n";
		try
		{
			Bureaucrat kyolee("kyole", 1);
			ShrubberyCreationForm form("kyolee2");
			RobotomyRequestForm form2("kyolee2");
			PresidentialPardonForm form3("kyolee3");

			kyolee.signForm(form);
			kyolee.signForm(form2);
			kyolee.signForm(form3);

			kyolee.executeForm(form);
			kyolee.executeForm(form2);
			kyolee.executeForm(form3);
			std::cout << std::endl;
			std::cout << form << std::endl;
			std::cout << std::endl;
			std::cout << form2 << std::endl;
			std::cout << std::endl;
			std::cout << form3 << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	
	return (0);
}
