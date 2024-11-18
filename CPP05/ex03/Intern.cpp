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

// Intern const &Intern::operator=(Intern const &rhs)
// {
// 	return (*this);
// } // TODO

AForm *Intern::makeForm(std::string name, std::string target)
{

	AForm *rrf = new RobotomyRequestForm(target);
	AForm *ppf = new PresidentialPardonForm(target);
	AForm *scf = new ShrubberyCreationForm(target);

	std::string formNames[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm *forms[] = {rrf, ppf, scf};
	for (int i = 0; i < 3; ++i)
	{
		if (formNames[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			for (int j = 0; j < 3; ++j)
				if (i != j)
					delete forms[j];
			return forms[i];
		}
	}
	delete rrf;
	delete ppf;
	delete scf;
	throw std::invalid_argument("Invalid request");
}
