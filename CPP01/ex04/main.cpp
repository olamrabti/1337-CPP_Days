
#include "find_and_replace.class.hpp"

int main(int ac, char *av[])
{
    if (ac == 4)
    {
        FindAndReplace replacer(av[1], av[2], av[3]);
        replacer.find_and_replace();
    }
    else
        std::cerr << "WRONG NUMBER OF PARAMETERS" << std::endl;
    return 0;
};