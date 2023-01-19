#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		//Bureaucrat person("kyolee", 170);
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

	return (0);
}
