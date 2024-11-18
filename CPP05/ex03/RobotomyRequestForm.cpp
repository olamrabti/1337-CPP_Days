#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Roboto", 72, 45), _target(target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm const &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (isSigned() == false)
		throw "Form Not signed";
	if (executor.getGrade() < 1) // TODO is it the appropriate check  ????
		throw GradeTooHighException();
	if (executor.getGrade() > 150) // TODO is it the appropriate check  ????
		throw GradeTooLowException();
	std::cout << " 🛠️  Drilling Noises 🛠️ " << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "robotomy failed." << std::endl;
}
