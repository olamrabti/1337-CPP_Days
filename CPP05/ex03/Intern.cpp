#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern::~Intern(void) {}

Intern const &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

AForm *Intern::createRRF(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPPF(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::createSCF(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *(Intern::*functions[])(std::string) = {&Intern::createRRF, &Intern::createPPF, &Intern::createSCF};

	std::string forms[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	for (int i = 0; i < 3; ++i)
	{
		if (forms[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*functions[i])(target);
		}
	}

	throw std::invalid_argument("Invalid request");
}
