#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Please provide an RPN expression." << std::endl;
        return 1;
    }

    RPN rpn;
    rpn.store_numbers(ac, av);
    std::cout << "Result: " << rpn.get_result() << std::endl;

    return 0;
}
