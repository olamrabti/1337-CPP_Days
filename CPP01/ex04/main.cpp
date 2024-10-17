
#include "find_and_replace.class.hpp"

int main(int ac, char *av[])
{

    if (av[2][0] == '\0')
    {
        std::cerr << "INVALID INPUT" << std::endl;
        return 1;
    }
    if (ac == 4)
    {
        FindAndReplace replacer(av[1], av[2], av[3]);
        replacer.find_and_replace();
    }
    else
        std::cerr << "WRONG NUMBER OF PARAMETERS" << std::endl;
    return 0;
};