#include "harl.class.hpp"

int main()
{
    Harl harl;

    std::cout << "DEBUG level:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\nINFO level:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nWARNING level:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\nERROR level:" << std::endl;
    harl.complain("ERROR");

    return 0;
}