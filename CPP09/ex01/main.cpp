#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error:  Invalid Input." << std::endl;
        return 1;
    }

    RPN rpn;
    try
    {
        rpn.parse_numbers(av[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
