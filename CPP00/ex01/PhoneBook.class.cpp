#include "PhoneBook.class.hpp"

void PhoneBook::search_contact(void)
{
    size_t i = 0;
    std::string input;

    std::cout << "|";
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "FirstName" << "|"
              << std::setw(10) << "LastName" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << " ------------------------------------------- " << std::endl;
    while (i <= 8)
        this->print_contact(this->_contact[i++]);
    std::cout << " ------------------------------------------- " << std::endl;
    std::cout << " ENTER INDEX : " << std::endl;
    std::getline(std::cin, input);
    for (int j = 0; j < 9; j++)
    {
        if (j == std::atoi(input.c_str()))
            this->print_contact(this->_contact[j]);
        if (std::atoi(input.c_str()) >= 9)
        {
            std::cout << " Makayench had number" << std::endl;
            break;
        }
    }
}

void PhoneBook::print_contact(Contact contact) const
{
    std::cout << "|";
    std::cout << std::setw(10) << contact.get_index() << "|";
    if (contact.get_firstname().length() <= 10)
        std::cout << std::setw(10) << contact.get_firstname() << "|";
    else
    {
        for (int i = 0; i < 9; i++)
            std::cout << contact.get_firstname()[i];
        std::cout << "." << "|";
    }
    if (contact.get_lastname().length() <= 10)
        std::cout << std::setw(10) << contact.get_lastname() << "|";
    else
    {
        for (int i = 0; i < 9; i++)
            std::cout << contact.get_lastname()[i];
        std::cout << "." << "|";
    }
    if (contact.get_nickname().length() <= 10)
        std::cout << std::setw(10) << contact.get_nickname() << "|";
    else
    {
        for (int i = 0; i < 9; i++)
            std::cout << contact.get_nickname()[i];
        std::cout << "." << "|";
    }
    std::cout << std::endl;
}

size_t PhoneBook::get_last_index(void) const
{
    return this->_last_index;
}

void PhoneBook::set_last_index()
{
    if (this->_last_index < 8)
        this->_last_index++;
    else if (this->_last_index > 8)
        this->_last_index = 0;
};

void PhoneBook::add_contact(Contact contact)
{
    std::string input;

    input = "";
    while (input.empty())
    {
        std::cout << "ENTER FIRSTNAME:  ";
        std::getline(std::cin, input);
    }
    contact.set_firstname(input);
    input = "";
    while (input.empty())
    {
        std::cout << "ENTER LASTNAME:  ";
        std::getline(std::cin, input);
    }
    contact.set_lastname(input);
    input = "";
    while (input.empty())
    {
        std::cout << "ENTER NICKNAME:  ";
        std::getline(std::cin, input);
    }
    contact.set_nickname(input);
    input = "";
    while (input.empty())
    {
        std::cout << "ENTER PHONE_NUMBER:  ";
        std::getline(std::cin, input);
    }
    contact.set_phonenumber(input);
    input = "";
    while (input.empty())
    {
        std::cout << "ENTER DARKEST_SECRET:  ";
        std::getline(std::cin, input);
    }
    contact.set_secret(input);
    contact.set_index(this->get_last_index());
    this->_contact[get_last_index()] = contact;
    this->set_last_index();
};

PhoneBook::PhoneBook()
{
    this->_last_index = 0;
    std::cout << "construtor is called" << std::endl;
};

PhoneBook::~PhoneBook()
{
    std::cout << "destrutor is called" << std::endl;
};