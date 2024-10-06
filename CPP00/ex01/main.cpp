#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main()
{
    std::string cmd;
    Contact test; // will be removed later
    PhoneBook phone_book;

    while (cmd != "EXIT")
    {
        if (cmd == "ADD")
            phone_book.add_contact(test);
        else if (cmd == "SEARCH")
            phone_book.search_contact();
        else if (!cmd.empty())
            std::cout << "YOUR CMD " << "\"" << cmd << "\" IS NOT ONE OF THE OPTIONS" << std::endl;
        cmd = "";
        std::cout << "ENTER A COMMAND (ADD, SEARCH OR EXIT) :  ";
        std::getline(std::cin, cmd);
    }
    return 0;
}