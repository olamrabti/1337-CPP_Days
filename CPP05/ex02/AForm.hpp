#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
private:
	std::string const form_name;
	bool _signed;
	size_t const sign_grade;
	size_t const exec_grade;

public:
	AForm(void);
	AForm(std::string name, size_t s_grade, size_t e_grade);
	AForm(AForm const &src);
	virtual ~AForm(void);
	AForm const &operator=(AForm const &rhs);
	std::string const &getName() const;
	size_t const &get_s_grade() const;
	size_t const &get_e_grade() const;
	bool const &isSigned() const;
	void beSigned(Bureaucrat const &b);
	virtual void execute(Bureaucrat const &executor) const = 0;
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
std::ostream &operator<<(std::ostream &os, AForm const &f);

#endif