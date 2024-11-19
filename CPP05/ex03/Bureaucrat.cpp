#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, size_t grade) : _name(name)
{
	if (grade < 1)
	{
		std::cout << "Bureaucrat Instantiation Error : ";
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		std::cout << "Bureaucrat Instantiation Error : ";
		throw GradeTooLowException();
	}
	_grade = grade;
}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		_grade = rhs._grade;
	return (*this);
}
Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name)
{
	*this = src;
}

Bureaucrat::~Bureaucrat(void) {}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

std::string const &Bureaucrat::getName() const
{
	return _name;
}

size_t const &Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{

	if (_grade > 1)
	{
		_grade--;
		std::cout << "Incremented by 1 : ";
		std::cout << *this << std::endl;
	}
	else
	{

		std::cout << "Cannot Increment : ";
		throw GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade()
{

	if (_grade < 150)
	{
		_grade++;
		std::cout << "Decremented by 1 : ";
		std::cout << *this << std::endl;
	}
	else
	{
		std::cout << "Cannot Decrement : ";
		throw GradeTooLowException();
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

void Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
};

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "ExecuteForm Error: " << e.what() << std::endl;
	}
	catch (const char *e)
	{
		std::cerr << "ExecuteForm Error: " << e << std::endl;
	}
	catch (...)
	{
		std::cerr << "Undefined Error" << std::endl;
	}
}