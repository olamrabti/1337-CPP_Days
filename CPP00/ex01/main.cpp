#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main()
{
    std::string cmd;
    Contact tmp;
    PhoneBook phone_book;

    while (1)
    {
        std::cout << "ENTER A COMMAND (ADD, SEARCH OR EXIT) :  ";
        std::getline(std::cin, cmd);
        if (cmd == "EXIT" || std::cin.eof())
            break;
        if (cmd == "ADD")
            phone_book.add_contact(tmp);
        else if (cmd == "SEARCH")
            phone_book.search_contact();
        else if (!cmd.empty())
            std::cout << "YOUR CMD " << "\"" << cmd << "\" IS NOT ONE OF THE OPTIONS" << std::endl;
        cmd.clear();
    }
    return 0;
}