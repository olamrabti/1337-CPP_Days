#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"
class Form;

class Bureaucrat
{
private:
	Bureaucrat(void);

protected:
	std::string const _name;
	size_t _grade;

public:
	Bureaucrat(std::string const name, size_t grade);
	Bureaucrat(Bureaucrat const &copy);
	Bureaucrat const &operator=(Bureaucrat const &rhs);
	~Bureaucrat(void);
	std::string const &getName() const;
	size_t const &getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &f);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif