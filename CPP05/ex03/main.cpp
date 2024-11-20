#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 50);
        Bureaucrat b2("Bob", 100);

        ShrubberyCreationForm form1("home");
        std::cout << "------------Test 1 (ShrubberyCreationForm)------------" << std::endl;

        b1.signForm(form1);
        std::cout << form1 << std::endl;
        b1.executeForm(form1);

        RobotomyRequestForm form2("target1");
        std::cout << "------------Test 2 (RobotomyRequestForm)------------" << std::endl;

        b2.signForm(form2);
        std::cout << form2 << std::endl;
        b1.executeForm(form2);

        PresidentialPardonForm form3("target2");
        std::cout << "------------Test 3 (PresidentialPardonForm)------------" << std::endl;

        b1.signForm(form3);
        std::cout << form3 << std::endl;
        b2.executeForm(form3);

        std::cout << "------------Test 4 (Unsigned Form)------------" << std::endl;
        Bureaucrat b3("Charlie", 150);
        PresidentialPardonForm form4("target3");

        b3.executeForm(form4);

        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        b1.signForm(*rrf);
    }
    catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
