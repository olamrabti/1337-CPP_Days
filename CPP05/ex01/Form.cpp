#include "Form.hpp"

Form::Form(std::string name, size_t s_grade, size_t e_grade)
	: form_name(name), _signed(false), sign_grade(s_grade), exec_grade(e_grade)
{
	if (sign_grade < 1 || exec_grade < 1)
	{
		std::cout << "Form Instantiation Error : ";
		throw GradeTooHighException();
	}
	if (sign_grade > 150 || exec_grade > 150)
	{
		std::cout << "Form Instantiation Error : ";
		throw GradeTooLowException();
	}
}

Form::Form(Form const &src)
	: form_name(src.form_name), sign_grade(src.sign_grade),
	  exec_grade(src.exec_grade)
{
	*this = src;
}

Form::~Form()
{
}

Form const &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

std::string const &Form::getName() const
{
	return form_name;
};
size_t const &Form::get_s_grade() const
{
	return sign_grade;
};
size_t const &Form::get_e_grade() const
{
	return exec_grade;
};
bool const &Form::isSigned() const
{
	return _signed;
};
void Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() <= sign_grade)
		_signed = true;
	else
		throw GradeTooLowException();
};

std::ostream &operator<<(std::ostream &os, Form const &f)
{
	os << "Form Infos : " << std::endl;
	os << " Name : " << f.getName() << std::endl;
	os << " Signed : " << (f.isSigned() ? "YES" : "No") << std::endl;
	os << " Grade required to sign : " << f.get_s_grade() << std::endl;
	os << " Grade required to execute : " << f.get_e_grade() << std::endl;
	return os;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}