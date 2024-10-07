#include <iostream>

int main(int ac, char *av[])
{
    int i = 1;
    if (ac >= 2)
    {
        while (i < ac)
        {
            std::string arg = av[i];
            for (std::size_t j = 0; j < arg.length(); j++)
                std ::cout << (char)(toupper(arg[j]));
            i++;
        }
    }
    else
        std ::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std ::cout << std ::endl, 0;
    return 0;
}