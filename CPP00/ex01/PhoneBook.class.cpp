#include "PhoneBook.class.hpp"

void PhoneBook::search_contact(void)
{
    size_t i = 0;
    std::string input;

    std::cout << " ------------------------------------------- " << std::endl;
    std::cout << "|";
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "FirstName" << "|"
              << std::setw(10) << "LastName" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << " ------------------------------------------- " << std::endl;
    if (this->_contact[0].get_index() == 99)
    {
        std::cout << "            PHONEBOOK IS EMPTY " << std::endl
                  << std::endl;
        return;
    }
    while (i < 8)
        this->print_contact(this->_contact[i++]);
    std::cout << " ------------------------------------------- " << std::endl;
    while (1)
    {
        std::cout << " ENTER INDEX : " << std::endl;
        std::getline(std::cin, input);
        if (input == "EXIT")
            exit(0);
        if (input.length() > 1 || std::atoi(input.c_str()) >= 8 || !std::isdigit(input[0]))
        {
            if (!std::isdigit(input[0]))
                std::cout << "INVALID : INPUT MUST BE A DIGIT" << std::endl;
            else
                std::cout << "INVALID : OUT OF RANGE (0 -> 7)" << std::endl;
        }
        else
        {
            for (int j = 0; j < 8; j++)
            {
                if (j == std::atoi(input.c_str()))
                {
                    if (this->_contact[j].get_index() == 99)
                        std::cout << "CONTACT NOT FOUND !" << std::endl;
                    else
                    {
                        std::cout << " ------------------------------------------- " << std::endl;
                        this->print_contact(this->_contact[j]);
                        std::cout << " ------------------------------------------- " << std::endl;
                    }
                }
            }
            break;
        }
    }
}

void PhoneBook::print_contact(Contact contact) const
{
    if (contact.get_index() == 99)
        return;
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
    this->_last_index = (this->_last_index + 1) % 8;
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
    std::cout << "PHONEBOOK 2.0" << std::endl;
};

PhoneBook::~PhoneBook()
{
    return;
};