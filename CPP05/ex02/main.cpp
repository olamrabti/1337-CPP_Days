#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 50);
        Bureaucrat b2("Bob", 100);

        ShrubberyCreationForm form1("home");
        std::cout << "------------Test 1 (ShrubberyCreationForm)------------" << std::endl;

        // Bureaucrat b1 signs the form
        b1.signForm(form1);
        std::cout << form1 << std::endl;

        // Bureaucrat b1 tries to execute the form
        b1.executeForm(form1);

        RobotomyRequestForm form2("target1");
        std::cout << "------------Test 2 (RobotomyRequestForm)------------" << std::endl;

        // Bureaucrat b2 signs the form
        b2.signForm(form2);
        std::cout << form2 << std::endl;

        // Bureaucrat b1 (who has a higher grade) tries to execute the form
        b1.executeForm(form2);

        PresidentialPardonForm form3("target2");
        std::cout << "------------Test 3 (PresidentialPardonForm)------------" << std::endl;

        // Bureaucrat b1 signs the form
        b1.signForm(form3);
        std::cout << form3 << std::endl;

        // Bureaucrat b2 tries to execute the form (Bob has a low enough grade)
        b2.executeForm(form3);

        // Try to execute the form with an unsigned form
        std::cout << "------------Test 4 (Unsigned Form)------------" << std::endl;
        Bureaucrat b3("Charlie", 150); // Grade 150 (too low for signing any forms)
        PresidentialPardonForm form4("target3");
        try
        {
            b3.executeForm(form4); // Should throw an exception as the form is unsigned
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
