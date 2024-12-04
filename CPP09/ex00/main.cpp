#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        try
        {
            BitcoinExchange operation;
            operation.store_data();
            // operation.print_data();
            operation.process_input_file(av[1]);
        }
        catch (std::exception const &e)
        {
            std::cerr << e.what() << std::endl;
        }
        // [ ] Open files, check if empty.
        // [ ] instantiate the class and pass the file stream (data.csv) to store values in the container
        // [ ] Display the values
    }
    return 0;
}