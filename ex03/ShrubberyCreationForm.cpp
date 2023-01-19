#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
 : AForm("ShrubberyCreation", SIGN_GRADE, EXEC_GRADE),
   _target(target)
{
	std::cout << "ShrubberyCreationForm Default Constructor Called\n";
}
	
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor Called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rShr)
: AForm(rShr), _target(rShr._target)
{
	std::cout << "ShrubberyCreationForm Copy Constructor Called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rShr)
{
	if (this == &rShr)
		return (*this);
	std::cout << "ShrubberyCreationForm Copy Assignment Operator Called\n";
	AForm::operator=(rShr);
	const_cast<std::string&>(_target) = rShr._target;
	return (*this);	
}
	

const std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw NoSignException();
	if (executor.getGrade() > getExecGrade())
		throw ExecGradeTooLowException();	
	const std::string fileName = _target + "_shrubbery";
	std::ofstream fout(fileName.c_str());
	if (!fout.is_open())
		throw FileOpenException(fileName);
	
	fout << "               ,@@@@@@@," << "\n";
	fout << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << "\n";
	fout << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << "\n";
	fout << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << "\n";
	fout << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << "\n";
	fout << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << "\n";
	fout << "   `&%\\ ` /%&'    |.|        \\ '|8'" << "\n";
	fout << "       |o|        | |         | |" << "\n";
	fout << "       |.|        | |         | |" << "\n";
	fout << "     \\/ ._\\//_/__/  ,\\_//___\\/.  \\_//__/_" << "\n";
  
	fout.close();
	std::cout << "Created a file which name of " << _target << "_shrubbery in working directory\n";
}

std::ostream& operator<<(std::ostream &os, const  ShrubberyCreationForm& rShr)
{
	std::cout << "Target : " << rShr.getTarget() << std::endl;
	std::cout << static_cast<const AForm&>(rShr);

	return (os);
}

ShrubberyCreationForm::FileOpenException::FileOpenException(const std::string& fileName)
 : _fileName(fileName)
{
	std::cout << "FileOpenException Construction Called\n";
}

ShrubberyCreationForm::FileOpenException::~FileOpenException() throw()
{
	std::cout << "FileOpenException Destruction Called\n";
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return ("Creating File is Failed");
}
