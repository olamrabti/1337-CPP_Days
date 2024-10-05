#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main()
{
    std::string cmd;
    Contact test;
    PhoneBook phone_book;

    std::cout << "ENTER A COMMAND (ADD, SEARCH OR EXIT) :  ";
    std::cin >> cmd;
    while (1) // first one is not accepted even if it is correct, idk why!!
    {
        if (cmd == "ADD")
            phone_book.add_contact(test);
        else if (cmd == "SEARCH")
            phone_book.search_contact();
        else if (cmd == "EXIT")
            break;
        else if (!cmd.empty())
        {
            std::cout << "YOUR CMD " << "\"" << cmd << "\" IS NOT ONE OF THE OPTIONS" << std::endl;
            std::cout << "ENTER YOUR COMMAND (ADD, SEARCH OR EXIT) :  ";
            std::cin >> cmd;
        }
        cmd = "";
        std::cout << "ENTER A COMMAND (ADD, SEARCH OR EXIT) :  ";
        std::cin >> cmd;
    }
    // std::cout << "CURRENT CONTACT IS: " << test.get_firstname();
    // std::cout << " " << test.get_lastname();
    // std::cout << " " << test.get_nickname();
    // std::cout << " | TEL:  " << test.get_phonenumber();
    // std::cout << " |  HIS SECRET IS :  " << test.get_secret() << std::endl;
    return 0;
}