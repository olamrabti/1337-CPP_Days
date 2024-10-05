#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include <string>
#include <iostream>
#include "Contact.class.hpp"

class PhoneBook
{
private:
    Contact contact[8];

public:
    PhoneBook();
    ~PhoneBook();
    void add_contact(Contact contact);
    void search_contact(void);
};

#endif