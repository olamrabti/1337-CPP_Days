#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "------------test 1: Valid Sign----------" << std::endl;
        Bureaucrat b1("John", 10);
        Form f1("Tax Form", 20, 10);
        b1.signForm(f1);
        std::cout << f1 << std::endl;

        std::cout << "------------test 2: Too Low Grade to Sign----------" << std::endl;
        Bureaucrat b2("Doe", 30);
        Form f2("Permit", 20, 30);
        b2.signForm(f2);
        std::cout << f2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "------------test 3: Edge Case - Minimum Grade----------" << std::endl;
        Bureaucrat b3("Min", 1);
        Form f3("VIP Form", 1, 1);
        b3.signForm(f3);
        std::cout << f3 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "------------test 4: Edge Case - Maximum Grade----------" << std::endl;
        Bureaucrat b4("Max", 150);
        Form f4("General Form", 150, 150);
        b4.signForm(f4);
        std::cout << f4 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "------------test 5: Invalid Bureaucrat Grade----------" << std::endl;
        Bureaucrat b5("Invalid", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "------------test 6: Invalid Form Grade----------" << std::endl;
        Form f5("Faulty Form", 151, 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
