#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm const &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (isSigned() == false)
		throw "Form Not signed";
	if (executor.getGrade() < 1)
		throw GradeTooHighException();
	if (executor.getGrade() > 150)
		throw GradeTooLowException();
	std::ofstream outfile(_target + "_shrubbery");
	if (outfile.fail())
	{
		throw "Unable to create file " + _target + "_shrubbery";
		// TODO file failure exception, learn more!
	}

	outfile << "        *        " << std::endl;
	outfile << "       /|\\       " << std::endl;
	outfile << "      /*|O\\      " << std::endl;
	outfile << "     /*/|\\*\\     " << std::endl;
	outfile << "    /X/O|*\\X\\    " << std::endl;
	outfile << "   /*/X/|\\O\\*\\   " << std::endl;
	outfile << "  /O/*/X|*\\O\\X\\  " << std::endl;
	outfile << " /X/O/*/|\\X\\O\\*\\ " << std::endl;
	outfile << "/O/X/*/X|O\\X\\*\\O\\" << std::endl;
	outfile << "        ||        " << std::endl;
	outfile << "        ||        " << std::endl;

	outfile.close();
}
