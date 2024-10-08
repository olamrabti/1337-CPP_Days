#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

#define EMPTY 3

class PhoneBook
{
private:
    Contact _contact[8];
    size_t _last_index;

public:
    PhoneBook();
    ~PhoneBook();
    void add_contact(Contact contact);
    void search_contact(void);
    int print_contacts(void) const;
    size_t get_last_index(void) const;
    void set_last_index();
};

#endif