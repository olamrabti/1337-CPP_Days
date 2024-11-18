#include "AForm.hpp"

AForm::AForm(void) : form_name("DEFAULT"), _signed(false), sign_grade(0), exec_grade(0)
{
}

AForm::AForm(std::string name, size_t s_grade, size_t e_grade)
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

AForm::~AForm()
{
}
AForm::AForm(AForm const &src)
	: form_name(src.form_name),
	  _signed(src._signed),
	  sign_grade(src.sign_grade),
	  exec_grade(src.exec_grade)
{
}

AForm const &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return (*this);
}

std::string const &AForm::getName() const
{
	return form_name;
};
size_t const &AForm::get_s_grade() const
{
	return sign_grade;
};
size_t const &AForm::get_e_grade() const
{
	return exec_grade;
};
bool const &AForm::isSigned() const
{
	return _signed;
};
void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() <= sign_grade)
		_signed = true;
	else
		throw GradeTooLowException();
};

std::ostream &operator<<(std::ostream &os, AForm const &f)
{
	os << "Form Infos : " << std::endl;
	os << " Name : " << f.getName() << std::endl;
	os << " Signed : " << (f.isSigned() ? "YES" : "No") << std::endl;
	os << " Grade required to sign : " << f.get_s_grade() << std::endl;
	os << " Grade required to execute : " << f.get_e_grade() << std::endl;
	return os;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}