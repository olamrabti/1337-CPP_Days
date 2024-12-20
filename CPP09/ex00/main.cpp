#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        try
        {
            BitcoinExchange operation;
            operation.store_data();
            operation.process_input_file(av[1]);
        }
        catch (std::exception const &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}