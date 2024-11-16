#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n------------test 1----------" << std::endl;
    Bureaucrat b1("B1", 149);
    try
    {
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        b1.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n------------test 2----------" << std::endl;
    try
    {
        Bureaucrat b2("B2", 2);
        std::cout << b2 << std::endl;
        b2.incrementGrade();
        b2.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n------------test 3----------" << std::endl;
    try
    {
        Bureaucrat b3("B3", 156);
        std::cout << b3 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}