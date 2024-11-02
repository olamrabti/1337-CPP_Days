#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook()
{
    _last_index = 0;
    std::cout << "PHONEBOOK 2.0" << std::endl;
};

PhoneBook::~PhoneBook() {};

bool is_all_spaces(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isspace((char)str[i]))
            return false;
    }
    return true;
}

void PhoneBook::search_contact(void)
{
    std::string input;

    std::cout << " ------------------------------------------- " << std::endl;
    std::cout << "|";
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "FirstName" << "|"
              << std::setw(10) << "LastName" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << " ------------------------------------------- " << std::endl;
    if (print_contacts() == EMPTY)
        return;
    std::cout << " ------------------------------------------- " << std::endl;
    while (1)
    {
        std::cout << " SELECT INDEX : " << std::endl;
        std::getline(std::cin, input);
        if (input == "EXIT" || std::cin.eof())
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
                    if (_contact[j].get_index() == 99)
                        std::cout << "CONTACT NOT FOUND !" << std::endl;
                    else
                    {
                        std::cout << " \nSELECTED CONTACT :" << std::endl;
                        std::cout << " ------------------------------------------- " << std::endl;
                        _contact[j].display_contact();
                        std::cout << " ------------------------------------------- " << std::endl;
                    }
                }
            }
            break;
        }
    }
}

int PhoneBook::print_contacts(void) const
{
    if (_contact[0].get_index() == 99)
    {
        std::cout << "            PHONEBOOK IS EMPTY " << std::endl
                  << std::endl;
        return EMPTY;
    }
    for (int j = 0; j < 8; j++)
    {

        if (_contact[j].get_index() == 99)
            return 0;
        std::cout << "|";
        std::cout << std::setw(10) << _contact[j].get_index() << "|";
        if (_contact[j].get_firstname().length() <= 10)
            std::cout << std::setw(10) << _contact[j].get_firstname() << "|";
        else
        {
            for (int i = 0; i < 9; i++)
                std::cout << _contact[j].get_firstname()[i];
            std::cout << "." << "|";
        }
        if (_contact[j].get_lastname().length() <= 10)
            std::cout << std::setw(10) << _contact[j].get_lastname() << "|";
        else
        {
            for (int i = 0; i < 9; i++)
                std::cout << _contact[j].get_lastname()[i];
            std::cout << "." << "|";
        }
        if (_contact[j].get_nickname().length() <= 10)
            std::cout << std::setw(10) << _contact[j].get_nickname() << "|";
        else
        {
            for (int i = 0; i < 9; i++)
                std::cout << _contact[j].get_nickname()[i];
            std::cout << "." << "|";
        }
        std::cout << std::endl;
    }
    return 0;
}

size_t PhoneBook::get_last_index(void) const
{
    return _last_index;
}

void PhoneBook::set_last_index()
{
    _last_index = (_last_index + 1) % 8;
};

void PhoneBook::add_contact(Contact contact)
{
    std::string input;

    input = "";
    while (1)
    {
        std::cout << "ENTER FIRSTNAME:  ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (!input.empty() && !is_all_spaces(input))
            break;
    }
    contact.set_firstname(input);
    input = "";
    while (1)
    {
        std::cout << "ENTER LASTNAME:  ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (!input.empty() && !is_all_spaces(input))
            break;
    }
    contact.set_lastname(input);
    input = "";
    while (input.empty())
    {
        std::cout << "ENTER NICKNAME:  ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (!input.empty() && !is_all_spaces(input))
            break;
    }
    contact.set_nickname(input);
    input = "";
    while (1)
    {
        std::cout << "ENTER PHONE_NUMBER:  ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (!input.empty() && !is_all_spaces(input))
            break;
    }
    contact.set_phonenumber(input);
    input = "";
    while (1)
    {
        std::cout << "ENTER DARKEST_SECRET:  ";
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (!input.empty() && !is_all_spaces(input))
            break;
    }
    contact.set_secret(input);
    contact.set_index(get_last_index());
    _contact[get_last_index()] = contact;
    set_last_index();
};
