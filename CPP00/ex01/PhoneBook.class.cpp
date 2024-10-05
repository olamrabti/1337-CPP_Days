#include "PhoneBook.class.hpp"

void PhoneBook::search_contact(void)
{
    std::cout << "search is called" << std::endl;
};

void PhoneBook::add_contact(Contact contact)
{
    std::string cmd;

    cmd = "";
    while (cmd.empty())
    {
        std::cout << "ENTER FIRSTNAME:  ";
        std::cin >> cmd;
    }
    contact.set_firstname(cmd);
    cmd = "";
    while (cmd.empty())
    {
        std::cout << "ENTER LASTNAME:  ";
        std::cin >> cmd;
    }
    contact.set_lastname(cmd);
    cmd = "";
    while (cmd.empty())
    {
        std::cout << "ENTER NICKNAME:  ";
        std::cin >> cmd;
    }
    contact.set_nickname(cmd);
    cmd = "";
    while (cmd.empty())
    {
        std::cout << "ENTER PHONE_NUMBER:  ";
        std::cin >> cmd;
    }
    contact.set_phonenumber(cmd);
    cmd = "";
    while (cmd.empty())
    {
        std::cout << "ENTER DARKEST_SECRET:  ";
        std::cin >> cmd;
    }
    contact.set_secret(cmd);
};

PhoneBook::PhoneBook()
{
    std::cout << "construtor is called" << std::endl;
};

PhoneBook::~PhoneBook()
{
    std::cout << "destrutor is called" << std::endl;
};