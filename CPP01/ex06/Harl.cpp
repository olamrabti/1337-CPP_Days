#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "\n[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
};

void Harl::info(void)
{
    std::cout << "\n[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger !If you did, I wouldn \'t be asking for more!" << std::endl;
};

void Harl::warning(void)
{
    std::cout << "\n[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month." << std::endl;
};

void Harl::error(void)
{
    std::cout << "\n[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    int i;

    if (level == "DEBUG")
        i = 0;
    else if (level == "INFO")
        i = 1;
    else if (level == "WARNING")
        i = 2;
    else if (level == "ERROR")
        i = 3;
    else
        i = -1;

    switch (i)
    {
    case 0:
        this->debug();
    case 1:
        this->info();
    case 2:
        this->warning();
    case 3:
        this->error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
