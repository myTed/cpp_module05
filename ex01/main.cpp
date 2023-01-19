#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{
	{
		try
		{
			Bureaucrat person("kyolee", 120);
			std::cout << person << std::endl;
			Bureaucrat person2("kyolee2", 151);
		
		
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
			Bureaucrat kyolee("kyole", 10);
			Form form("form", 10, 20);

			kyolee.signForm(form);
			std::cout << std::endl;
			std::cout << form << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	
	return (0);
}
