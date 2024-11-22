#include "ScalarConverte.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
        ScalarConverte::convert(av[1]);
    return 0;
}