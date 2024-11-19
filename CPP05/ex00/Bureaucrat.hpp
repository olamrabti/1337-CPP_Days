#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	std::string const _name;
	size_t _grade;
	Bureaucrat(void);

public:
	Bureaucrat(std::string const name, size_t grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat const &operator=(Bureaucrat const &rhs);
	~Bureaucrat(void);
	std::string const &getName() const;
	size_t const &getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};
std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif