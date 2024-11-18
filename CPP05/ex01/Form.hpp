#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
	std::string const form_name;
	bool _signed;
	size_t const sign_grade;
	size_t const exec_grade;
	Form(void);

public:
	Form(std::string name, size_t s_grade, size_t e_grade);
	Form(Form const &src);
	~Form(void);
	Form const &operator=(Form const &rhs);
	std::string const &getName() const;
	size_t const &get_s_grade() const;
	size_t const &get_e_grade() const;
	bool const &isSigned() const;
	void beSigned(Bureaucrat const &b);
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
std::ostream &operator<<(std::ostream &os, Form const &f);

#endif